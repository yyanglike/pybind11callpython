#!/bin/bash

# ============================================
# 股票数据获取系统清理脚本
# 作者: Stock Data System Development Team
# 日期: 2025-12-12
# ============================================

set -e  # 遇到错误时退出

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 日志函数
log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

log_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# 显示帮助信息
show_help() {
    echo "股票数据获取系统清理脚本"
    echo ""
    echo "用法: ./cleanup.sh [选项]"
    echo ""
    echo "选项:"
    echo "  -h, --help          显示此帮助信息"
    echo "  -a, --all           清理所有内容（默认）"
    echo "  -p, --process       仅清理进程"
    echo "  -f, --files         仅清理文件"
    echo "  -l, --lock          仅清理锁文件"
    echo "  -c, --csv           仅清理CSV数据文件"
    echo "  -b, --build         清理build目录"
    echo "  -v, --verbose       显示详细输出"
    echo ""
    echo "示例:"
    echo "  ./cleanup.sh              # 清理所有内容"
    echo "  ./cleanup.sh -p -f        # 清理进程和文件"
    echo "  ./cleanup.sh -c           # 仅清理CSV文件"
    echo ""
}

# 初始化变量
CLEAN_PROCESS=false
CLEAN_FILES=false
CLEAN_LOCK=false
CLEAN_CSV=false
CLEAN_BUILD=false
CLEAN_ALL=true
VERBOSE=false

# 解析命令行参数
while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            show_help
            exit 0
            ;;
        -a|--all)
            CLEAN_ALL=true
            shift
            ;;
        -p|--process)
            CLEAN_PROCESS=true
            CLEAN_ALL=false
            shift
            ;;
        -f|--files)
            CLEAN_FILES=true
            CLEAN_ALL=false
            shift
            ;;
        -l|--lock)
            CLEAN_LOCK=true
            CLEAN_ALL=false
            shift
            ;;
        -c|--csv)
            CLEAN_CSV=true
            CLEAN_ALL=false
            shift
            ;;
        -b|--build)
            CLEAN_BUILD=true
            CLEAN_ALL=false
            shift
            ;;
        -v|--verbose)
            VERBOSE=true
            shift
            ;;
        *)
            log_error "未知选项: $1"
            show_help
            exit 1
            ;;
    esac
done

# 如果指定了特定选项，则使用特定清理
if [ "$CLEAN_ALL" = true ]; then
    CLEAN_PROCESS=true
    CLEAN_FILES=true
    CLEAN_LOCK=true
    CLEAN_CSV=true
    CLEAN_BUILD=false  # 默认不清理build目录，只清理数据文件
fi

# 显示清理计划
log_info "开始清理操作..."
if [ "$CLEAN_PROCESS" = true ]; then
    log_info "✓ 将清理相关进程"
fi
if [ "$CLEAN_LOCK" = true ]; then
    log_info "✓ 将清理锁文件"
fi
if [ "$CLEAN_CSV" = true ]; then
    log_info "✓ 将清理CSV数据文件"
fi
if [ "$CLEAN_BUILD" = true ]; then
    log_info "✓ 将清理build目录"
fi
echo ""

# 函数：清理进程
cleanup_processes() {
    log_info "清理相关进程..."
    
    # 查找并终止stock_data_app进程
    local pids=$(pgrep -f "stock_data_app" 2>/dev/null || true)
    if [ -n "$pids" ]; then
        if [ "$VERBOSE" = true ]; then
            log_info "找到stock_data_app进程: $pids"
        fi
        kill -9 $pids 2>/dev/null || true
        sleep 1
        log_success "已终止stock_data_app进程"
    else
        log_info "未找到stock_data_app进程"
    fi
    
    # 查找并终止multiprocessing.resource_tracker进程
    local mp_pids=$(pgrep -f "multiprocessing.resource_tracker" 2>/dev/null || true)
    if [ -n "$mp_pids" ]; then
        if [ "$VERBOSE" = true ]; then
            log_info "找到multiprocessing.resource_tracker进程: $mp_pids"
        fi
        kill -9 $mp_pids 2>/dev/null || true
        sleep 1
        log_success "已终止multiprocessing.resource_tracker进程"
    else
        log_info "未找到multiprocessing.resource_tracker进程"
    fi
    
    # 查找并终止python相关进程（如果使用了子进程）
    local py_pids=$(pgrep -f "python.*get_data\|python.*tdx_data_handler" 2>/dev/null || true)
    if [ -n "$py_pids" ]; then
        if [ "$VERBOSE" = true ]; then
            log_info "找到Python数据获取进程: $py_pids"
        fi
        kill -9 $py_pids 2>/dev/null || true
        sleep 1
        log_success "已终止Python数据获取进程"
    fi
    
    # 等待一小段时间确保进程完全终止
    sleep 2
}

# 函数：清理锁文件
cleanup_lock_files() {
    log_info "清理锁文件..."
    
    # 锁文件路径
    local lock_files=(
        "/tmp/stock_data_app.lock"
        "/tmp/stock_fetch_interrupt"
        "/tmp/stock_data_lock"
    )
    
    local cleaned=0
    for lock_file in "${lock_files[@]}"; do
        if [ -f "$lock_file" ]; then
            if [ "$VERBOSE" = true ]; then
                log_info "删除锁文件: $lock_file"
            fi
            rm -f "$lock_file"
            cleaned=$((cleaned + 1))
        fi
    done
    
    if [ $cleaned -gt 0 ]; then
        log_success "已清理 $cleaned 个锁文件"
    else
        log_info "未找到锁文件"
    fi
}

# 函数：清理CSV数据文件
cleanup_csv_files() {
    log_info "清理CSV数据文件..."
    
    local cleaned=0
    
    # 清理build/data/目录
    if [ -d "build/data" ]; then
        local file_count=$(find build/data -name "*.csv" -type f | wc -l)
        if [ $file_count -gt 0 ]; then
            if [ "$VERBOSE" = true ]; then
                log_info "清理build/data/目录中的 $file_count 个CSV文件"
            fi
            
            # 使用find命令删除，避免参数过多的问题
            find build/data -name "*.csv" -type f -delete
            
            # 检查是否还有.DS_Store文件
            find build/data -name ".DS_Store" -type f -delete 2>/dev/null || true
            
            cleaned=$((cleaned + file_count))
            log_success "已清理build/data/目录中的CSV文件"
        else
            log_info "build/data/目录中没有CSV文件"
        fi
    else
        log_info "build/data/目录不存在"
    fi
    
    # 清理python/data/目录
    if [ -d "python/data" ]; then
        local file_count=$(find python/data -name "*.csv" -type f | wc -l)
        if [ $file_count -gt 0 ]; then
            if [ "$VERBOSE" = true ]; then
                log_info "清理python/data/目录中的 $file_count 个CSV文件"
            fi
            
            find python/data -name "*.csv" -type f -delete
            find python/data -name ".DS_Store" -type f -delete 2>/dev/null || true
            
            cleaned=$((cleaned + file_count))
            log_success "已清理python/data/目录中的CSV文件"
        else
            log_info "python/data/目录中没有CSV文件"
        fi
    else
        log_info "python/data/目录不存在"
    fi
    
    # 清理deploy/python/data/目录
    if [ -d "deploy/python/data" ]; then
        local file_count=$(find deploy/python/data -name "*.csv" -type f | wc -l)
        if [ $file_count -gt 0 ]; then
            if [ "$VERBOSE" = true ]; then
                log_info "清理deploy/python/data/目录中的 $file_count 个CSV文件"
            fi
            
            find deploy/python/data -name "*.csv" -type f -delete
            find deploy/python/data -name ".DS_Store" -type f -delete 2>/dev/null || true
            
            cleaned=$((cleaned + file_count))
            log_success "已清理deploy/python/data/目录中的CSV文件"
        else
            log_info "deploy/python/data/目录中没有CSV文件"
        fi
    fi
    
    if [ $cleaned -gt 0 ]; then
        log_success "总共清理了 $cleaned 个CSV文件"
    else
        log_info "未找到CSV数据文件"
    fi
}

# 函数：清理临时文件
cleanup_temp_files() {
    log_info "清理临时文件..."
    
    local cleaned=0
    
    # 清理临时目录中的相关文件
    local temp_files=$(find /tmp -name "stock_*" -type f 2>/dev/null || true)
    if [ -n "$temp_files" ]; then
        if [ "$VERBOSE" = true ]; then
            log_info "找到临时文件:"
            echo "$temp_files"
        fi
        
        find /tmp -name "stock_*" -type f -delete 2>/dev/null || true
        cleaned=$(echo "$temp_files" | wc -l)
    fi
    
    # 清理项目根目录下的临时文件
    local project_temp_files=$(find . -name "*.tmp" -o -name "*.temp" -o -name "*.log" -type f 2>/dev/null || true)
    if [ -n "$project_temp_files" ]; then
        if [ "$VERBOSE" = true ]; then
            log_info "找到项目临时文件:"
            echo "$project_temp_files"
        fi
        
        find . -name "*.tmp" -o -name "*.temp" -o -name "*.log" -type f -delete 2>/dev/null || true
        cleaned=$((cleaned + $(echo "$project_temp_files" | wc -l)))
    fi
    
    if [ $cleaned -gt 0 ]; then
        log_success "已清理 $cleaned 个临时文件"
    else
        log_info "未找到临时文件"
    fi
}

# 函数：清理build目录
cleanup_build_dir() {
    log_warning "清理build目录..."
    
    if [ -d "build" ]; then
        if [ "$VERBOSE" = true ]; then
            log_info "删除build目录..."
        fi
        
        # 先清理data子目录中的文件，避免权限问题
        if [ -d "build/data" ]; then
            rm -rf build/data
        fi
        
        # 删除整个build目录
        rm -rf build
        
        log_success "已清理build目录"
    else
        log_info "build目录不存在"
    fi
}

# 函数：显示清理摘要
show_summary() {
    echo ""
    log_info "========== 清理完成 =========="
    log_info "当前状态:"
    
    # 检查进程状态
    local process_count=$(pgrep -f "stock_data_app\|multiprocessing.resource_tracker" 2>/dev/null | wc -l || echo "0")
    if [ $process_count -eq 0 ]; then
        log_success "✓ 无相关进程运行"
    else
        log_warning "⚠ 仍有 $process_count 个相关进程运行"
    fi
    
    # 检查锁文件
    local lock_count=0
    if [ -f "/tmp/stock_data_app.lock" ]; then
        lock_count=$((lock_count + 1))
    fi
    if [ -f "/tmp/stock_fetch_interrupt" ]; then
        lock_count=$((lock_count + 1))
    fi
    
    if [ $lock_count -eq 0 ]; then
        log_success "✓ 无锁文件存在"
    else
        log_warning "⚠ 仍有 $lock_count 个锁文件存在"
    fi
    
    # 检查CSV文件
    local csv_count=0
    if [ -d "build/data" ]; then
        csv_count=$((csv_count + $(find build/data -name "*.csv" -type f 2>/dev/null | wc -l || echo "0")))
    fi
    if [ -d "python/data" ]; then
        csv_count=$((csv_count + $(find python/data -name "*.csv" -type f 2>/dev/null | wc -l || echo "0")))
    fi
    
    if [ $csv_count -eq 0 ]; then
        log_success "✓ 无CSV数据文件"
    else
        log_warning "⚠ 仍有 $csv_count 个CSV文件存在"
    fi
    
    echo ""
    log_info "清理脚本已完成！"
    log_info "现在可以安全地重新运行股票数据获取系统。"
}

# 主清理流程
main() {
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}    股票数据获取系统清理工具${NC}"
    echo -e "${BLUE}========================================${NC}"
    echo ""
    
    # 检查是否以root权限运行（仅在需要时）
    if [ "$CLEAN_PROCESS" = true ] && [ "$EUID" -eq 0 ]; then
        log_warning "警告：以root权限运行可能过度终止进程"
        read -p "是否继续？(y/N): " -n 1 -r
        echo
        if [[ ! $REPLY =~ ^[Yy]$ ]]; then
            log_info "清理已取消"
            exit 0
        fi
    fi
    
    # 执行清理操作
    if [ "$CLEAN_PROCESS" = true ]; then
        cleanup_processes
    fi
    
    if [ "$CLEAN_LOCK" = true ]; then
        cleanup_lock_files
    fi
    
    if [ "$CLEAN_CSV" = true ]; then
        cleanup_csv_files
    fi
    
    if [ "$CLEAN_FILES" = true ]; then
        cleanup_temp_files
    fi
    
    if [ "$CLEAN_BUILD" = true ]; then
        cleanup_build_dir
    fi
    
    # 显示清理摘要
    show_summary
}

# 执行主函数
main

exit 0
