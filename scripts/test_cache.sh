#!/bin/bash
# 统一的缓存测试脚本 - 整合了所有缓存相关的测试功能

set -e

cd "$(dirname "$0")/.."

MODE="${1:-quick}"  # 默认快速测试

# 显示帮助信息
show_help() {
    cat << EOF
用法: $0 [MODE] [OPTIONS]

测试模式:
  quick        - 快速缓存性能对比（前10个用例，默认）
  full         - 完整缓存一致性验证（所有用例）
  compare      - 对比指定脚本的缓存性能
  repeated     - 测试重复定义函数的缓存性能

选项:
  --iterations N  - 设置迭代次数（默认：quick=1, compare=5, repeated=10）
  --script FILE   - 指定测试脚本（用于compare和repeated模式）

示例:
  $0 quick                    # 快速测试
  $0 full                     # 完整验证
  $0 compare --script python/test_cache_performance.pys  # 对比指定脚本
  $0 repeated --iterations 20  # 测试重复定义，迭代20次
EOF
}

# 清理输出函数
clean_output() {
    cat "$1" | \
    grep -v "^\[INFO\]" | \
    grep -v "^\[DEBUG\]" | \
    grep -v "^\[WARN\]" | \
    grep -v "^\[ERROR\]" | \
    grep -v "Function/class definition caching is disabled" | \
    sed 's/Current time: [0-9-]* [0-9:.]*/Current time: <TIMESTAMP>/g' | \
    sed 's/[0-9]\{4\}-[0-9]\{2\}-[0-9]\{2\} [0-9]\{2\}:[0-9]\{2\}:[0-9]\{2\}\.[0-9]*/<TIMESTAMP>/g' | \
    sort
}

# 快速缓存性能对比（前10个用例）
run_quick_test() {
    echo "=== 快速缓存性能对比（前10个测试用例）==="
    echo ""
    
    local total=0
    local cache_time_sum=0
    local no_cache_time_sum=0
    
    for f in python/*.pys; do
        if [ $total -ge 10 ]; then
            break
        fi
        
        total=$((total + 1))
        filename=$(basename "$f")
        
        # 运行开启缓存的版本并计时
        cache_start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script "$f" >/dev/null 2>&1
        cache_end=$(python3 -c "import time; print(time.time())")
        cache_time=$(python3 -c "print($cache_end - $cache_start)")
        
        # 运行关闭缓存的版本并计时
        no_cache_start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script --no-cache "$f" >/dev/null 2>&1
        no_cache_end=$(python3 -c "import time; print(time.time())")
        no_cache_time=$(python3 -c "print($no_cache_end - $no_cache_start)")
        
        # 累计时间
        cache_time_sum=$(python3 -c "print($cache_time_sum + $cache_time)")
        no_cache_time_sum=$(python3 -c "print($no_cache_time_sum + $no_cache_time)")
        
        # 显示结果
        speedup=$(python3 -c "print('%.2f' % ($no_cache_time / $cache_time))" 2>/dev/null || echo "N/A")
        echo "$filename: 缓存=${cache_time}s, 无缓存=${no_cache_time}s, 加速=${speedup}x"
    done
    
    echo ""
    echo "=== 汇总 ==="
    echo "测试用例数: $total"
    echo "总时间（开启缓存）: ${cache_time_sum}s"
    echo "总时间（关闭缓存）: ${no_cache_time_sum}s"
    if python3 -c "exit(0 if $no_cache_time_sum > 0 else 1)" 2>/dev/null; then
        overall_speedup=$(python3 -c "print('%.2f' % ($no_cache_time_sum / $cache_time_sum))")
        echo "整体加速比: ${overall_speedup}x"
        time_saved=$(python3 -c "print($no_cache_time_sum - $cache_time_sum)")
        echo "节省时间: ${time_saved}s"
    fi
}

# 完整缓存一致性验证
run_full_test() {
    local total=0
    local passed=0
    local failed=0
    local failed_files=()
    
    # 性能统计
    local total_cache_time=0
    local total_no_cache_time=0
    local cache_faster_count=0
    local no_cache_faster_count=0
    
    echo "=== 缓存一致性验证和性能对比 ==="
    echo ""
    
    for f in python/*.pys; do
        total=$((total + 1))
        filename=$(basename "$f")
        
        # 运行开启缓存的版本并计时
        cache_start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script "$f" 2>&1 > /tmp/cache_${total}.txt
        cache_end=$(python3 -c "import time; print(time.time())")
        cache_time=$(python3 -c "print($cache_end - $cache_start)")
        cache_output=$(clean_output /tmp/cache_${total}.txt)
        
        # 运行关闭缓存的版本并计时
        no_cache_start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script --no-cache "$f" 2>&1 > /tmp/no_cache_${total}.txt
        no_cache_end=$(python3 -c "import time; print(time.time())")
        no_cache_time=$(python3 -c "print($no_cache_end - $no_cache_start)")
        no_cache_output=$(clean_output /tmp/no_cache_${total}.txt)
        
        # 累计时间
        total_cache_time=$(python3 -c "print($total_cache_time + $cache_time)")
        total_no_cache_time=$(python3 -c "print($total_no_cache_time + $no_cache_time)")
        
        # 比较输出
        if [ "$cache_output" = "$no_cache_output" ]; then
            passed=$((passed + 1))
            echo "[$total] ✓ $filename - 输出一致"
        else
            failed=$((failed + 1))
            failed_files+=("$filename")
            echo "[$total] ✗ $filename - 输出不一致"
        fi
        
        # 性能比较
        if python3 -c "exit(0 if $cache_time < $no_cache_time else 1)" 2>/dev/null; then
            cache_faster_count=$((cache_faster_count + 1))
        else
            no_cache_faster_count=$((no_cache_faster_count + 1))
        fi
    done
    
    echo ""
    echo "=== 一致性验证结果 ==="
    echo "Total: $total | Passed: $passed | Failed: $failed"
    
    if [ ${#failed_files[@]} -gt 0 ]; then
        echo ""
        echo "Failed files:"
        for f in "${failed_files[@]}"; do
            echo "  - $f"
        done
    fi
    
    echo ""
    echo "=== 性能对比结果 ==="
    echo "总时间（开启缓存）: ${total_cache_time}s"
    echo "总时间（关闭缓存）: ${total_no_cache_time}s"
    if python3 -c "exit(0 if $total_no_cache_time > 0 else 1)" 2>/dev/null; then
        overall_speedup=$(python3 -c "print('%.2f' % ($total_no_cache_time / $total_cache_time))")
        echo "整体加速比: ${overall_speedup}x"
    fi
    echo "缓存更快: $cache_faster_count | 无缓存更快: $no_cache_faster_count"
    
    # 清理临时文件
    rm -f /tmp/cache_*.txt /tmp/no_cache_*.txt
    
    if [ $failed -gt 0 ]; then
        exit 1
    else
        exit 0
    fi
}

# 对比指定脚本的缓存性能
run_compare_test() {
    local script="${SCRIPT:-python/test_cache_performance.pys}"
    local iterations="${ITERATIONS:-5}"
    
    if [ ! -f "$script" ]; then
        echo "ERROR: Script not found: $script"
        exit 1
    fi
    
    echo "=== 缓存性能对比测试 ==="
    echo "测试脚本: $script"
    echo "迭代次数: $iterations"
    echo ""
    
    # 测试开启缓存
    echo "--- 开启缓存 ---"
    local cache_times=()
    for i in $(seq 1 $iterations); do
        start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script --cache "$script" > /dev/null 2>&1
        end=$(python3 -c "import time; print(time.time())")
        elapsed=$(python3 -c "print($end - $start)")
        cache_times+=($elapsed)
        echo "  迭代 $i: ${elapsed}s"
    done
    
    # 计算平均值
    cache_avg=$(python3 -c "times = [$(IFS=+; echo "${cache_times[*]}")]; print(sum(times) / len(times))")
    echo "  平均时间: ${cache_avg}s"
    echo ""
    
    # 测试关闭缓存
    echo "--- 关闭缓存 ---"
    local no_cache_times=()
    for i in $(seq 1 $iterations); do
        start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script --no-cache "$script" > /dev/null 2>&1
        end=$(python3 -c "import time; print(time.time())")
        elapsed=$(python3 -c "print($end - $start)")
        no_cache_times+=($elapsed)
        echo "  迭代 $i: ${elapsed}s"
    done
    
    # 计算平均值
    no_cache_avg=$(python3 -c "times = [$(IFS=+; echo "${no_cache_times[*]}")]; print(sum(times) / len(times))")
    echo "  平均时间: ${no_cache_avg}s"
    echo ""
    
    # 计算加速比
    speedup=$(python3 -c "print($no_cache_avg / $cache_avg)")
    echo "=== 结果对比 ==="
    echo "开启缓存平均时间: ${cache_avg}s"
    echo "关闭缓存平均时间: ${no_cache_avg}s"
    echo "加速比: ${speedup}x"
    
    if python3 -c "exit(0 if $speedup > 1.0 else 1)" 2>/dev/null; then
        echo "✅ 缓存提升了性能！"
    else
        echo "⚠️  缓存未提升性能（可能因为函数只定义一次，未触发缓存机制）"
    fi
}

# 测试重复定义函数的缓存性能
run_repeated_test() {
    local script="${SCRIPT:-python/test_cache_repeated_def.pys}"
    local iterations="${ITERATIONS:-10}"
    
    if [ ! -f "$script" ]; then
        echo "ERROR: Script not found: $script"
        exit 1
    fi
    
    echo "=== 重复定义函数缓存性能测试 ==="
    echo "测试脚本: $script"
    echo "迭代次数: $iterations"
    echo ""
    
    # 测试开启缓存
    echo "--- 开启缓存 ---"
    local cache_times=()
    for i in $(seq 1 $iterations); do
        start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script --cache "$script" > /dev/null 2>&1
        end=$(python3 -c "import time; print(time.time())")
        elapsed=$(python3 -c "print($end - $start)")
        cache_times+=($elapsed)
        printf "  迭代 %2d: %.6fs\n" $i $elapsed
    done
    
    # 计算平均值
    cache_sum=$(python3 -c "times = [$(IFS=+; echo "${cache_times[*]}")]; print(sum(times))")
    cache_avg=$(python3 -c "print($cache_sum / $iterations)")
    echo "  平均时间: ${cache_avg}s"
    echo ""
    
    # 测试关闭缓存
    echo "--- 关闭缓存 ---"
    local no_cache_times=()
    for i in $(seq 1 $iterations); do
        start=$(python3 -c "import time; print(time.time())")
        ./build/run_pys_script --no-cache "$script" > /dev/null 2>&1
        end=$(python3 -c "import time; print(time.time())")
        elapsed=$(python3 -c "print($end - $start)")
        no_cache_times+=($elapsed)
        printf "  迭代 %2d: %.6fs\n" $i $elapsed
    done
    
    # 计算平均值
    no_cache_sum=$(python3 -c "times = [$(IFS=+; echo "${no_cache_times[*]}")]; print(sum(times))")
    no_cache_avg=$(python3 -c "print($no_cache_sum / $iterations)")
    echo "  平均时间: ${no_cache_avg}s"
    echo ""
    
    # 计算加速比
    speedup=$(python3 -c "print($no_cache_avg / $cache_avg)")
    time_saved=$(python3 -c "print($no_cache_avg - $cache_avg)")
    
    echo "=== 结果 ==="
    echo "开启缓存（平均）:    ${cache_avg}s"
    echo "关闭缓存（平均）:    ${no_cache_avg}s"
    echo "加速比:              ${speedup}x"
    echo "节省时间:            ${time_saved}s"
    
    if python3 -c "exit(0 if $speedup > 1.0 else 1)" 2>/dev/null; then
        improvement=$(python3 -c "print(($no_cache_avg - $cache_avg) / $no_cache_avg * 100)")
        echo "✅ 缓存提升了性能 ${improvement}%"
    else
        echo "⚠️  缓存未提升性能（加速比 < 1.0）"
    fi
}

# 解析参数
SCRIPT=""
ITERATIONS=""

while [[ $# -gt 0 ]]; do
    case $1 in
        --help|-h)
            show_help
            exit 0
            ;;
        --script)
            SCRIPT="$2"
            shift 2
            ;;
        --iterations)
            ITERATIONS="$2"
            shift 2
            ;;
        *)
            if [ -z "$MODE_SET" ]; then
                MODE="$1"
                MODE_SET=true
            fi
            shift
            ;;
    esac
done

# 根据模式运行测试
case "$MODE" in
    quick)
        run_quick_test
        ;;
    full)
        run_full_test
        ;;
    compare)
        run_compare_test
        ;;
    repeated)
        run_repeated_test
        ;;
    *)
        echo "Unknown mode: $MODE"
        show_help
        exit 1
        ;;
esac

