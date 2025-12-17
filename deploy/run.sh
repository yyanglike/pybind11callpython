#!/bin/bash
# 股票数据获取系统启动脚本

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
EXECUTABLE="$SCRIPT_DIR/stock_data_app"

# 设置Python环境变量
export PYTHONHOME="$SCRIPT_DIR/.venv"
export PYTHONPATH="$SCRIPT_DIR/.venv/lib/python3.14/site-packages:$SCRIPT_DIR/python"

# 设置可执行文件权限
chmod +x "$EXECUTABLE" 2>/dev/null

# 运行程序
"$EXECUTABLE" "$@"
