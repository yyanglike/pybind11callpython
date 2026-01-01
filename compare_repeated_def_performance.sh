#!/bin/bash
# Compare cache performance for repeated function definitions

SCRIPT="test_cache_repeated_def.pys"
ITERATIONS=10

echo "=== Cache Performance Comparison for Repeated Function Definitions ==="
echo "Test script: $SCRIPT"
echo "Iterations: $ITERATIONS"
echo ""

# Test with cache enabled
echo "--- With Cache Enabled ---"
cache_times=()
for i in $(seq 1 $ITERATIONS); do
    start=$(python3 -c "import time; print(time.time())")
    ./build/run_pys_script --cache "$SCRIPT" > /dev/null 2>&1
    end=$(python3 -c "import time; print(time.time())")
    elapsed=$(python3 -c "print($end - $start)")
    cache_times+=($elapsed)
    printf "  Iteration %2d: %.6fs\n" $i $elapsed
done

# Calculate average
cache_sum=$(python3 -c "times = [$(IFS=+; echo "${cache_times[*]}")]; print(sum(times))")
cache_avg=$(python3 -c "print($cache_sum / $ITERATIONS)")
echo "  Average time: ${cache_avg}s"
echo ""

# Test with cache disabled
echo "--- With Cache Disabled ---"
no_cache_times=()
for i in $(seq 1 $ITERATIONS); do
    start=$(python3 -c "import time; print(time.time())")
    ./build/run_pys_script --no-cache "$SCRIPT" > /dev/null 2>&1
    end=$(python3 -c "import time; print(time.time())")
    elapsed=$(python3 -c "print($end - $start)")
    no_cache_times+=($elapsed)
    printf "  Iteration %2d: %.6fs\n" $i $elapsed
done

# Calculate average
no_cache_sum=$(python3 -c "times = [$(IFS=+; echo "${no_cache_times[*]}")]; print(sum(times))")
no_cache_avg=$(python3 -c "print($no_cache_sum / $ITERATIONS)")
echo "  Average time: ${no_cache_avg}s"
echo ""

# Calculate speedup
speedup=$(python3 -c "print($no_cache_avg / $cache_avg)")
time_saved=$(python3 -c "print($no_cache_avg - $cache_avg)")

echo "=== Results ==="
echo "With cache (average):    ${cache_avg}s"
echo "Without cache (average): ${no_cache_avg}s"
echo "Speedup:                ${speedup}x"
echo "Time saved:             ${time_saved}s"

if (( $(echo "$speedup > 1.0" | bc -l) )); then
    improvement=$(python3 -c "print(($no_cache_avg - $cache_avg) / $no_cache_avg * 100)")
    echo "✅ Cache improved performance by ${improvement}%"
else
    echo "⚠️  Cache did not improve performance (speedup < 1.0)"
    echo "   This may be because:"
    echo "   - Cache overhead exceeds benefit for this workload"
    echo "   - Function definitions are not being cached (check cache hit rate)"
fi

