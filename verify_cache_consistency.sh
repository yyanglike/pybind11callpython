#!/bin/bash
# 缓存一致性验证脚本
# 用途：验证开启和关闭缓存时脚本执行结果是否一致，并比较性能差异

cd "$(dirname "$0")"

# 清理函数：移除时间戳、日志等动态内容
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

total=0
passed=0
failed=0
failed_files=()

# 性能统计
total_cache_time=0
total_no_cache_time=0
cache_faster_count=0
no_cache_faster_count=0

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
    
    # 累计时间（使用临时文件避免变量传递问题）
    total_cache_time=$(python3 -c "print($total_cache_time + $cache_time)")
    total_no_cache_time=$(python3 -c "print($total_no_cache_time + $no_cache_time)")
    
    # 比较结果
    if [ "$cache_output" = "$no_cache_output" ]; then
        echo "✓ PASS: $filename"
        passed=$((passed + 1))
        
        # 性能比较（只显示有显著差异的，使用临时文件）
        time_diff=$(python3 -c "print($no_cache_time - $cache_time)")
        if python3 -c "exit(0 if $time_diff > 0.01 else 1)" 2>/dev/null; then
            speedup=$(python3 -c "print('%.2f' % ($no_cache_time / $cache_time))")
            echo "  ⚡ 缓存加速: ${speedup}x (缓存: ${cache_time}s, 无缓存: ${no_cache_time}s)"
            cache_faster_count=$((cache_faster_count + 1))
        elif python3 -c "exit(0 if $time_diff < -0.01 else 1)" 2>/dev/null; then
            slowdown=$(python3 -c "print('%.2f' % ($cache_time / $no_cache_time))")
            echo "  ⚠ 缓存略慢: ${slowdown}x (缓存: ${cache_time}s, 无缓存: ${no_cache_time}s)"
            no_cache_faster_count=$((no_cache_faster_count + 1))
        fi
    else
        echo "✗ FAIL: $filename"
        failed=$((failed + 1))
        failed_files+=("$filename")
        
        # 显示差异（前20行）
        echo "  Differences (first 10 lines):"
        diff -u <(echo "$cache_output") <(echo "$no_cache_output") 2>&1 | head -20 | sed 's/^/    /'
        echo ""
    fi
done

echo ""
echo "=== 总结 ==="
echo "总测试数: $total"
echo "通过: $passed"
echo "失败: $failed"
echo "通过率: $((passed * 100 / total))%"

if [ $failed -gt 0 ]; then
    echo ""
    echo "失败的测试用例:"
    for f in "${failed_files[@]}"; do
        echo "  - $f"
    done
fi

echo ""
echo "=== 性能统计 ==="
echo "总执行时间（开启缓存）: ${total_cache_time}s"
echo "总执行时间（关闭缓存）: ${total_no_cache_time}s"
if python3 -c "exit(0 if $total_no_cache_time > 0 else 1)" 2>/dev/null; then
    overall_speedup=$(python3 -c "print('%.2f' % ($total_no_cache_time / $total_cache_time))")
    echo "整体性能提升: ${overall_speedup}x"
    time_saved=$(python3 -c "print($total_no_cache_time - $total_cache_time)")
    echo "节省时间: ${time_saved}s"
    percent_improvement=$(python3 -c "print('%.1f' % (($total_no_cache_time - $total_cache_time) / $total_no_cache_time * 100))")
    echo "性能提升百分比: ${percent_improvement}%"
fi
echo "缓存更快的测试用例数: $cache_faster_count"
echo "无缓存更快的测试用例数: $no_cache_faster_count"

if [ $failed -eq 0 ]; then
    echo ""
    echo "✓ 所有测试用例在开启和关闭缓存时结果一致！"
    exit 0
else
    exit 1
fi

