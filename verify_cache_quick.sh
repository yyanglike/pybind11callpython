#!/bin/bash
# 快速缓存性能对比脚本（仅测试前10个用例）
# 用途：快速验证缓存性能提升效果

cd "$(dirname "$0")"

echo "=== 快速缓存性能对比（前10个测试用例）==="
echo ""

total=0
cache_time_sum=0
no_cache_time_sum=0

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

