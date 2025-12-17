#!/bin/bash
# 部署脚本：将可执行文件和虚拟环境打包

set -e

echo "========================================"
echo "股票数据获取系统 - 部署打包脚本"
echo "========================================"

# 获取项目根目录
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
DEPLOY_DIR="$PROJECT_ROOT/deploy"
PACKAGE_NAME="stock_data_system_$(date +%Y%m%d_%H%M%S)"

echo "项目根目录: $PROJECT_ROOT"
echo "构建目录: $BUILD_DIR"
echo "部署目录: $DEPLOY_DIR"

# 检查构建目录是否存在
if [ ! -d "$BUILD_DIR" ]; then
    echo "错误：构建目录不存在，请先运行 'cd build && cmake .. && make'"
    exit 1
fi

# 检查可执行文件是否存在
EXECUTABLE="$BUILD_DIR/stock_data_app"
if [ ! -f "$EXECUTABLE" ]; then
    echo "错误：可执行文件不存在: $EXECUTABLE"
    exit 1
fi

# 创建部署目录
echo "创建部署目录..."
rm -rf "$DEPLOY_DIR"
mkdir -p "$DEPLOY_DIR"

# 1. 复制可执行文件
echo "复制可执行文件..."
cp "$EXECUTABLE" "$DEPLOY_DIR/"

# 2. 复制Python虚拟环境（精简版本）
echo "复制Python虚拟环境..."
mkdir -p "$DEPLOY_DIR/.venv"

# 复制虚拟环境配置文件
cp "$PROJECT_ROOT/.venv/pyvenv.cfg" "$DEPLOY_DIR/.venv/"

# 复制bin目录（只复制必要的可执行文件）
mkdir -p "$DEPLOY_DIR/.venv/bin"
cp "$PROJECT_ROOT/.venv/bin/python" "$DEPLOY_DIR/.venv/bin/"
cp "$PROJECT_ROOT/.venv/bin/python3" "$DEPLOY_DIR/.venv/bin/"
cp "$PROJECT_ROOT/.venv/bin/python3.14" "$DEPLOY_DIR/.venv/bin/"

# 设置可执行权限
chmod +x "$DEPLOY_DIR/.venv/bin/python" "$DEPLOY_DIR/.venv/bin/python3" "$DEPLOY_DIR/.venv/bin/python3.14"

# 3. 复制必要的lib目录内容
echo "复制Python库文件..."
mkdir -p "$DEPLOY_DIR/.venv/lib/python3.14"

# 复制site-packages中的必要包
mkdir -p "$DEPLOY_DIR/.venv/lib/python3.14/site-packages"

# 创建__pycache__目录（空）
mkdir -p "$DEPLOY_DIR/.venv/lib/python3.14/__pycache__"

# 4. 复制项目Python代码
echo "复制项目Python代码..."
mkdir -p "$DEPLOY_DIR/python"
cp -r "$PROJECT_ROOT/python/"* "$DEPLOY_DIR/python/"

# 5. 创建启动脚本
echo "创建启动脚本..."
cat > "$DEPLOY_DIR/run.sh" << 'EOF'
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
EOF

chmod +x "$DEPLOY_DIR/run.sh"

# 6. 创建Windows批处理文件（可选）
cat > "$DEPLOY_DIR/run.bat" << 'EOF'
@echo off
REM 股票数据获取系统启动脚本（Windows）

set SCRIPT_DIR=%~dp0
set EXECUTABLE=%SCRIPT_DIR%\stock_data_app.exe

REM 设置Python环境变量
set PYTHONHOME=%SCRIPT_DIR%\.venv
set PYTHONPATH=%SCRIPT_DIR%\.venv\lib\python3.14\site-packages;%SCRIPT_DIR%\python

REM 运行程序
"%EXECUTABLE%" %*
EOF

# 7. 创建README文件
cat > "$DEPLOY_DIR/README.md" << 'EOF'
# 股票数据获取系统部署包

## 文件说明
- `stock_data_app` - 主程序可执行文件
- `.venv/` - Python虚拟环境（精简版）
- `python/` - 项目Python代码
- `run.sh` - Linux/macOS启动脚本
- `run.bat` - Windows启动脚本

## 使用方法

### Linux/macOS:
```bash
./run.sh [回溯天数]
```

示例：
```bash
./run.sh 100  # 获取100天的历史数据
```

### Windows:
```cmd
run.bat [回溯天数]
```

示例：
```cmd
run.bat 100
```

## 系统要求
- Linux/macOS/Windows
- 不需要单独安装Python
- 磁盘空间：约200MB
- 内存：至少1GB

## 注意事项
1. 第一次运行会自动下载股票数据到data/目录
2. 数据文件会保存在可执行文件同目录的data/文件夹中
3. 确保有网络连接以获取最新数据
```

# 8. 打包部署文件
echo "打包部署文件..."
cd "$PROJECT_ROOT"
tar -czf "${PACKAGE_NAME}.tar.gz" -C deploy .

# 计算大小
PACKAGE_SIZE=$(du -h "${PACKAGE_NAME}.tar.gz" | cut -f1)

echo "========================================"
echo "部署包创建完成！"
echo "文件名: ${PACKAGE_NAME}.tar.gz"
echo "大小: $PACKAGE_SIZE"
echo "位置: $PROJECT_ROOT"
echo ""
echo "使用方法:"
echo "1. 解压: tar -xzf ${PACKAGE_NAME}.tar.gz"
echo "2. 进入解压后的目录"
echo "3. 运行: ./run.sh [回溯天数]"
echo "========================================"

# 显示部署目录结构
echo ""
echo "部署目录结构:"
find "$DEPLOY_DIR" -type f | sort
