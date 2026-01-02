#!/bin/bash
# 快速测试脚本 - 测试所有文件但显示进度

cd "$(dirname "$0")/.."

INTERPRETER="./build/run_pys_script"
TEST_FILES=($(find python -name "*.pys" -type f | sort))

TOTAL=${#TEST_FILES[@]}
PASSED=0
FAILED=0
FAILED_LIST=()

echo "========================================="
echo "Running $TOTAL tests..."
echo "========================================="
echo ""

for i in "${!TEST_FILES[@]}"; do
    file="${TEST_FILES[$i]}"
    num=$((i + 1))
    
    # 每10个显示一次进度
    if [ $((num % 10)) -eq 0 ] || [ $num -eq $TOTAL ]; then
        echo "[Progress: $num/$TOTAL]"
    fi
    
    if timeout 10 $INTERPRETER "$file" >/dev/null 2>&1; then
        PASSED=$((PASSED + 1))
    else
        FAILED=$((FAILED + 1))
        FAILED_LIST+=("$file")
    fi
done

echo ""
echo "========================================="
echo "Test Summary"
echo "========================================="
echo "Total tests: $TOTAL"
echo "Passed: $PASSED"
echo "Failed: $FAILED"
if [ $TOTAL -gt 0 ]; then
    SUCCESS_RATE=$(( PASSED * 100 / TOTAL ))
    echo "Success rate: ${SUCCESS_RATE}%"
fi

if [ ${#FAILED_LIST[@]} -gt 0 ]; then
    echo ""
    echo "Failed tests (${#FAILED_LIST[@]}):"
    for f in "${FAILED_LIST[@]}"; do
        echo "  - $(basename $f)"
    done
fi

if [ $FAILED -gt 0 ]; then
    exit 1
else
    exit 0
fi
