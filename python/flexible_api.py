"""
灵活的股票数据API - 支持多种参数组合
"""

import pandas as pd
import os
import warnings
from tdx_data_handler import TDXDataHandler

warnings.filterwarnings("ignore", category=FutureWarning)

def get_stock_data(*args, **kwargs):
    """
    灵活的股票数据获取函数，支持多种参数组合
    
    参数模式:
    1. 无参数: get_stock_data() - 使用默认值
    2. 仅回溯天数: get_stock_data(100) 或 get_stock_data(lookback_days=100)
    3. 股票代码列表: get_stock_data(['000001', '000002'], 100)
    4. 完整参数: get_stock_data(stock_codes=['000001', '000002'], lookback_days=100, market='std')
    5. 混合模式: get_stock_data(['000001', '000002'], lookback_days=100, market='std')
    
    参数说明:
        stock_codes: 股票代码列表或字符串，默认为code.csv中的所有股票
        lookback_days: 回溯天数，默认365
        market: 市场类型，默认'std'（标准市场）
    
    返回:
        dict[str, DataFrame]: 股票代码 -> DataFrame的映射
    """
    # 默认参数
    stock_codes = None
    lookback_days = 365
    market = 'std'
    
    # 解析位置参数
    if len(args) > 0:
        if isinstance(args[0], (list, tuple, str)):
            stock_codes = args[0]
            if len(args) > 1:
                lookback_days = args[1]
                if len(args) > 2:
                    market = args[2]
        elif isinstance(args[0], (int, float)):
            lookback_days = int(args[0])
            if len(args) > 1:
                if isinstance(args[1], (list, tuple, str)):
                    stock_codes = args[1]
                else:
                    market = args[1]
    
    # 关键字参数覆盖位置参数
    if 'stock_codes' in kwargs:
        stock_codes = kwargs['stock_codes']
    if 'lookback_days' in kwargs:
        lookback_days = kwargs['lookback_days']
    if 'market' in kwargs:
        market = kwargs['market']
    
    print(f"[Python] 调用参数: stock_codes={stock_codes}, lookback_days={lookback_days}, market={market}")
    
    # 获取脚本所在目录
    script_dir = os.path.dirname(os.path.abspath(__file__))
    code_file = os.path.join(script_dir, "code.csv")
    
    # 如果指定了股票代码，使用指定代码，否则读取所有代码
    if stock_codes is None:
        filtered_data = pd.read_csv(code_file, dtype={"ts_code": str})
        stock_codes = filtered_data['ts_code'].tolist()
    elif isinstance(stock_codes, str):
        stock_codes = [stock_codes]
    
    # 创建数据处理器
    tdx_handler = TDXDataHandler(market=market)
    
    # 处理所有股票数据
    all_stock_data = tdx_handler.process_all_stocks(code_file=code_file, kline_count=lookback_days)
    
    # 如果指定了股票代码，只返回指定代码的数据
    if isinstance(stock_codes, (list, tuple)) and len(stock_codes) > 0:
        filtered_data = {}
        for code in stock_codes:
            code_str = str(code)
            if code_str in all_stock_data:
                filtered_data[code_str] = all_stock_data[code_str]
        return filtered_data
    
    return all_stock_data


def get_stock_data_simple(lookback_days=365):
    """
    简化版本，向后兼容
    
    参数:
        lookback_days: 回溯天数，默认365
    
    返回:
        dict[str, DataFrame]: 股票代码 -> DataFrame的映射
    """
    return get_stock_data(lookback_days=lookback_days)


def get_stock_data_with_codes(stock_codes, lookback_days=365):
    """
    指定股票代码版本
    
    参数:
        stock_codes: 股票代码列表或字符串
        lookback_days: 回溯天数，默认365
    
    返回:
        dict[str, DataFrame]: 股票代码 -> DataFrame的映射
    """
    return get_stock_data(stock_codes=stock_codes, lookback_days=lookback_days)


# 测试函数
if __name__ == "__main__":
    print("测试灵活API:")
    
    # 测试1: 无参数
    print("\n1. 无参数调用:")
    result1 = get_stock_data()
    print(f"  返回 {len(result1)} 只股票数据")
    
    # 测试2: 仅回溯天数
    print("\n2. 仅回溯天数:")
    result2 = get_stock_data(100)
    print(f"  返回 {len(result2)} 只股票数据")
    
    # 测试3: 位置参数
    print("\n3. 位置参数:")
    result3 = get_stock_data(['000001', '000002'], 50)
    print(f"  返回 {len(result3)} 只股票数据")
    
    # 测试4: 关键字参数
    print("\n4. 关键字参数:")
    result4 = get_stock_data(stock_codes=['000001'], lookback_days=30, market='std')
    print(f"  返回 {len(result4)} 只股票数据")
    
    # 测试5: 混合参数
    print("\n5. 混合参数:")
    result5 = get_stock_data(['000001'], market='std')
    print(f"  返回 {len(result5)} 只股票数据")
