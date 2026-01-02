# 脚本目录

本目录包含项目使用的各种脚本。

## 测试脚本

### test.sh - 统一测试脚本

整合了所有测试功能，支持多种测试模式：

```bash
# 运行所有测试
./scripts/test.sh

# 运行新功能测试
./scripts/test.sh new

# 运行简单测试
./scripts/test.sh simple

# 列出所有测试用例
./scripts/test.sh list

# 运行指定测试
./scripts/test.sh specific python/test_hello.pys

# 生成详细报告
./scripts/test.sh all --report

# 静默模式
./scripts/test.sh all --quiet
```

### test_cache.sh - 缓存测试脚本

整合了所有缓存相关的测试功能：

```bash
# 快速缓存性能对比（前10个用例）
./scripts/test_cache.sh quick

# 完整缓存一致性验证（所有用例）
./scripts/test_cache.sh full

# 对比指定脚本的缓存性能
./scripts/test_cache.sh compare --script python/test_cache_performance.pys

# 测试重复定义函数的缓存性能
./scripts/test_cache.sh repeated --iterations 20
```

## 根目录脚本

以下脚本保留在根目录，因为它们与项目构建和部署相关：

- `setup.sh` - 一键设置脚本
- `build.sh` - 构建脚本
- `install.sh` - 安装脚本
- `deploy.sh` - 部署脚本
- `cleanup.sh` - 清理脚本
