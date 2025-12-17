@echo off
REM 股票数据获取系统启动脚本（Windows）

set SCRIPT_DIR=%~dp0
set EXECUTABLE=%SCRIPT_DIR%\stock_data_app.exe

REM 设置Python环境变量
set PYTHONHOME=%SCRIPT_DIR%\.venv
set PYTHONPATH=%SCRIPT_DIR%\.venv\lib\python3.14\site-packages;%SCRIPT_DIR%\python

REM 运行程序
"%EXECUTABLE%" %*
