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



pkill -9 stock_data_app; sleep 1; ps aux | grep stock_data_app | grep -v grep | wc -l