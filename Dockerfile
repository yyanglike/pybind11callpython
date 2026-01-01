# Dockerfile for PyScript Interpreter
# 用于容器化部署

FROM ubuntu:22.04

# 设置环境变量
ENV DEBIAN_FRONTEND=noninteractive
ENV PYTHONUNBUFFERED=1

# 安装系统依赖
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    python3.12 \
    python3.12-venv \
    python3-pip \
    antlr4 \
    && rm -rf /var/lib/apt/lists/*

# 设置工作目录
WORKDIR /app

# 复制项目文件
COPY . .

# 创建虚拟环境并安装依赖
RUN python3.12 -m venv .venv && \
    .venv/bin/pip install --upgrade pip && \
    if [ -f requirements.txt ]; then .venv/bin/pip install -r requirements.txt; fi

# 生成ANTLR代码
RUN if [ -f antlr/PyScript.g4 ]; then \
    mkdir -p antlr/generated && \
    antlr4 -Dlanguage=Cpp -visitor -o antlr/generated antlr/PyScript.g4 2>&1 | grep -v "warning" || true; \
    fi

# 构建项目
RUN mkdir -p build && \
    cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    cmake --build . --target run_pys_script -j$(nproc)

# 设置入口点
ENTRYPOINT ["./build/run_pys_script"]
CMD ["--help"]

