# Makefile for PyScript Interpreter
# 简化常用操作的便捷命令

.PHONY: help setup build clean test install run deps venv antlr

# 默认目标
help:
	@echo "PyScript Interpreter - 可用命令："
	@echo ""
	@echo "  设置和构建："
	@echo "    make setup          - 一键设置（创建虚拟环境、安装依赖、构建）"
	@echo "    make build          - 构建项目"
	@echo "    make clean          - 清理构建文件"
	@echo "    make deps           - 安装Python依赖"
	@echo "    make venv           - 创建虚拟环境"
	@echo "    make antlr          - 生成ANTLR代码"
	@echo ""
	@echo "  运行和测试："
	@echo "    make run SCRIPT=... - 运行.pys脚本"
	@echo "    make test           - 运行所有测试"
	@echo "    make test-quick     - 快速测试（前10个用例）"
	@echo ""
	@echo "  安装："
	@echo "    make install        - 安装到系统（可选）"
	@echo ""
	@echo "  示例："
	@echo "    make setup"
	@echo "    make run SCRIPT=python/test_hello.pys"
	@echo "    make test"

# 一键设置
setup:
	@bash setup.sh

# 创建虚拟环境
venv:
	@if [ ! -d ".venv" ]; then \
		echo "创建虚拟环境..."; \
		python3 -m venv .venv; \
		echo "虚拟环境创建成功"; \
	else \
		echo "虚拟环境已存在"; \
	fi

# 安装Python依赖
deps: venv
	@echo "安装Python依赖..."
	@. .venv/bin/activate && pip install --upgrade pip && pip install -r requirements.txt

# 生成ANTLR代码
antlr:
	@if [ ! -f "antlr/PyScript.g4" ]; then \
		echo "错误：未找到antlr/PyScript.g4"; \
		exit 1; \
	fi
	@if ! command -v antlr4 &> /dev/null; then \
		echo "错误：未找到antlr4命令"; \
		exit 1; \
	fi
	@mkdir -p antlr/generated
	@echo "生成ANTLR代码..."
	@antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4 2>&1 | grep -v "warning" || true

# 构建项目
build: antlr
	@mkdir -p build
	@cd build && cmake .. -DCMAKE_BUILD_TYPE=Release
	@cd build && cmake --build . --target run_pys_script -j$$(sysctl -n hw.ncpu 2>/dev/null || nproc 2>/dev/null || echo 4)

# 清理构建文件
clean:
	@echo "清理构建文件..."
	@rm -rf build
	@rm -rf antlr/generated
	@echo "清理完成"

# 运行脚本
run:
	@if [ -z "$(SCRIPT)" ]; then \
		echo "错误：请指定脚本路径"; \
		echo "用法: make run SCRIPT=python/test_hello.pys"; \
		exit 1; \
	fi
	@if [ ! -f "./build/run_pys_script" ]; then \
		echo "错误：可执行文件不存在，请先运行 'make build'"; \
		exit 1; \
	fi
	@./build/run_pys_script $(SCRIPT)

# 运行所有测试
test:
	@if [ ! -f "./build/run_pys_script" ]; then \
		echo "错误：可执行文件不存在，请先运行 'make build'"; \
		exit 1; \
	fi
	@echo "运行所有测试..."
	@bash -c 'for f in python/*.pys; do echo "Testing: $$f"; ./build/run_pys_script "$$f" || exit 1; done'

# 快速测试
test-quick:
	@if [ ! -f "./build/run_pys_script" ]; then \
		echo "错误：可执行文件不存在，请先运行 'make build'"; \
		exit 1; \
	fi
	@echo "运行快速测试（前10个用例）..."
	@bash verify_cache_quick.sh

# 安装到系统（可选）
install: build
	@echo "安装到系统..."
	@sudo cp build/run_pys_script /usr/local/bin/pyscript
	@sudo chmod +x /usr/local/bin/pyscript
	@echo "安装完成！现在可以使用 'pyscript' 命令"

# 卸载
uninstall:
	@echo "卸载..."
	@sudo rm -f /usr/local/bin/pyscript
	@echo "卸载完成"

