import pandas as pd
import os

# 忽略 FutureWarning 警告，避免pandas等库输出无关警告
import warnings
warnings.filterwarnings("ignore", category=FutureWarning)


def get_all_stock_data(LOOKBACK_DAYS=365):
    # Get the directory where this script is located
    script_dir = os.path.dirname(os.path.abspath(__file__))
    code_file = os.path.join(script_dir, "code.csv")
    filtered_data = pd.read_csv(code_file, dtype={"ts_code": str})
    from tdx_data_handler import TDXDataHandler
    tdx_handler = TDXDataHandler(market="std")
    all_stock_data = tdx_handler.process_all_stocks(code_file=code_file, kline_count=LOOKBACK_DAYS)
    return all_stock_data
