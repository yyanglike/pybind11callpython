import random
from time import sleep
from mootdx.quotes import Quotes
import pandas as pd
from datetime import datetime, timedelta
from tqdm import tqdm
import os


class TDXDataHandler:
    def __init__(self, market="std"):
        """
        初始化通达信客户端
        """
        self.client = Quotes.factory(market=market, quiet=True)

    def get_stock_data(self, symbol, kline_count=None, data_dir="data"):
        """
        获取单只股票的日线数据
        :param symbol: 股票代码
        :param kline_count: 从后向前获取的 K 线数量
        :param data_dir: 存储 CSV 文件的目录
        :return: DataFrame
        """
        # 确保 data_dir 目录存在
        if not os.path.exists(data_dir):
            os.makedirs(data_dir)

        # 构造 CSV 文件路径
        csv_file = os.path.join(data_dir, f"{symbol}.csv")

        # 如果 CSV 文件存在，直接读取
        if os.path.exists(csv_file):
            try:
                # 检查文件是否为空
                if os.path.getsize(csv_file) == 0:
                    return pd.DataFrame()
                df = pd.read_csv(csv_file, index_col=0, parse_dates=True)
                # 如果读取的 DataFrame 为空，返回空
                if df.empty:
                    return pd.DataFrame()
            except Exception as e:
                # 静默处理错误，返回空的DataFrame
                df = pd.DataFrame()
        else:
            df = pd.DataFrame()
        
        # 如果 DataFrame 为空，从数据源获取
        if df.empty:
            # 如果文件不存在，从数据源读取
            # 获取最近一年的数据（大约 365 根 K 线）
            # frequency=9 表示日线，start=0 表示从第 0 根开始，end=800 表示获取 800 根（足够一年）
            try:
                df = self.client.bars(symbol=symbol, frequency=9, start=0, end=800, adjust='qfq')
                if df is None or df.empty:
                    # 如果获取失败，返回空的 DataFrame
                    return pd.DataFrame()
            except Exception as e:
                return pd.DataFrame()

            # 确保索引为日期类型
            if not isinstance(df.index, pd.DatetimeIndex):
                df.index = pd.to_datetime(df.index, errors='coerce')

            # 保存到 CSV 文件（仅当有数据时）
            if not df.empty:
                df.to_csv(csv_file)

        # 如果指定了 kline_count，则只返回最后 kline_count 行数据
        if kline_count is not None and kline_count > 0:
            df = df.tail(kline_count)

        return df

    def merge_data(self, df, qq):
        """
        合并行情数据到日线数据中
        :param df: 日线数据 DataFrame
        :param qq: 行情数据 DataFrame
        :return: 合并后的 DataFrame
        """
        today = pd.to_datetime(datetime.now().strftime('%Y-%m-%d'))
        for _, row in qq.iterrows():
            code = row['code']
            quote_data = {
                'open': float(row['open']) if 'open' in row else 0.0,
                'high': float(row['high']) if 'high' in row else 0.0,
                'low': float(row['low']) if 'low' in row else 0.0,
                'close': float(row['price']) if 'price' in row else 0.0,
                'amount': float(row['amount']) if 'amount' in row else 0.0,
                'volume': float(row['volume']) if 'volume' in row else 0.0,
                'factor': 1
            }

            # 检查是否存在今日数据
            if today in df.index:
                for col in ['open', 'high', 'low', 'close', 'amount', 'volume', 'factor']:
                    df.loc[today, col] = quote_data[col]
            else:
                # 追加今日数据
                df.loc[today] = quote_data

        return df

    def process_all_stocks(self, code_file, kline_count=None):
        """
        处理所有股票数据
        :param code_file: 包含股票代码的 CSV 文件路径
        :param kline_count: 从后向前获取的 K 线数量
        :return: 合并后的所有股票数据字典 {股票代码: DataFrame}
        """
        # 从 code.csv 中读取股票代码，确保 ts_code 列为字符串类型
        codes = pd.read_csv(code_file, dtype={'ts_code': str})['ts_code'].tolist()

        # 每 20 个股票分组
        grouped_codes = [codes[i:i + 20] for i in range(0, len(codes), 20)]

        all_data = {}
        # 使用简洁的进度条，减少输出干扰
        for group in tqdm(grouped_codes, desc="处理股票组", bar_format='{l_bar}{bar:30}{r_bar}', leave=False, mininterval=0.5):
            # 获取行情数据
            try:
                qq = self.client.quotes(symbol=group)
            except Exception as e:
                # 静默处理错误，继续下一组
                continue

            # 遍历每只股票，获取历史数据并合并实时行情（禁用内层进度条）
            for code in group:
                # 获取历史数据
                df = self.get_stock_data(symbol=str(code), kline_count=kline_count)
                if df.empty:
                    continue

                # 筛选当前股票的行情数据
                stock_qq = qq[qq['code'] == str(code)]
                if not stock_qq.empty and stock_qq['open'].iloc[0] > 0:
                    df = self.merge_data(df, stock_qq)

                all_data[str(code)] = df

        return all_data
