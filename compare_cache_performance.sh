#!/bin/bash
# 对比开启缓存和关闭缓存的性能差异

SCRIPT="test_cache_repeated_execution.pys"
ITERATIONS=5

echo "=== 缓存性能对比测试 ==="
echo "测试脚本: $SCRIPT"
echo "迭代次数: $ITERATIONS"
echo ""

# 测试开启缓存
echo "--- 开启缓存 ---"
cache_times=()
for i in $(seq 1 $ITERATIONS); do
    start=$(python3 -c "import time; print(time.time())")
    ./build/run_pys_script --cache "$SCRIPT" > /dev/null 2>&1
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
no_cache_times=()
for i in $(seq 1 $ITERATIONS); do
    start=$(python3 -c "import time; print(time.time())")
    ./build/run_pys_script --no-cache "$SCRIPT" > /dev/null 2>&1
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

if (( $(echo "$speedup > 1.0" | bc -l) )); then
    echo "✅ 缓存提升了性能！"
else
    echo "⚠️  缓存未提升性能（可能因为函数只定义一次，未触发缓存机制）"
fi

