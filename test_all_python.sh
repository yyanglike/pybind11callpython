#!/bin/bash

# 测试脚本 - 运行 python 目录下的所有 .pys 文件

INTERPRETER="./build/run_pys_script"
REPORT_FILE="test_all_python_report_$(date +%Y%m%d_%H%M%S).txt"
SUMMARY_FILE="test_summary.txt"

echo "=========================================" | tee "$REPORT_FILE"
echo "Test Execution Report - All Python Files" | tee -a "$REPORT_FILE"
echo "Date: $(date)" | tee -a "$REPORT_FILE"
echo "=========================================" | tee -a "$REPORT_FILE"
echo "" | tee -a "$REPORT_FILE"

# 检查解释器是否存在
if [ ! -f "$INTERPRETER" ]; then
    echo "ERROR: Interpreter not found at $INTERPRETER" | tee -a "$REPORT_FILE"
    echo "Please build the project first: cmake --build build" | tee -a "$REPORT_FILE"
    exit 1
fi

# 获取所有 .pys 文件
TEST_SCRIPTS=($(find python -name "*.pys" -type f | sort))

if [ ${#TEST_SCRIPTS[@]} -eq 0 ]; then
    echo "ERROR: No .pys files found in python directory" | tee -a "$REPORT_FILE"
    exit 1
fi

PASSED=0
FAILED=0
TOTAL=0
FAILED_TESTS=()

echo "Found ${#TEST_SCRIPTS[@]} test files" | tee -a "$REPORT_FILE"
echo "Running tests..." | tee -a "$REPORT_FILE"
echo "" | tee -a "$REPORT_FILE"

# 实时显示进度
for script in "${TEST_SCRIPTS[@]}"; do
    TOTAL=$((TOTAL + 1))
    script_name=$(basename "$script")
    
    # 显示进度（每10个或最后一个）
    if [ $((TOTAL % 10)) -eq 0 ] || [ $TOTAL -eq ${#TEST_SCRIPTS[@]} ]; then
        echo "[Progress: $TOTAL/${#TEST_SCRIPTS[@]}] Testing: $script_name" | tee -a "$REPORT_FILE"
    fi
    
    if [ ! -f "$script" ]; then
        echo "✗ FILE NOT FOUND: $script" | tee -a "$REPORT_FILE"
        FAILED=$((FAILED + 1))
        FAILED_TESTS+=("$script")
        continue
    fi
    
    # 运行测试（超时30秒）
    OUTPUT=$(timeout 30 $INTERPRETER "$script" 2>&1)
    EXIT_CODE=$?
    
    if [ $EXIT_CODE -eq 0 ]; then
        PASSED=$((PASSED + 1))
        # 成功时只记录到详细报告
        echo "[$TOTAL] ✓ $script_name" >> "$REPORT_FILE"
    else
        FAILED=$((FAILED + 1))
        FAILED_TESTS+=("$script")
        # 失败时记录详细信息
        echo "----------------------------------------" >> "$REPORT_FILE"
        echo "[$TOTAL] ✗ FAILED: $script_name (exit code: $EXIT_CODE)" >> "$REPORT_FILE"
        echo "File: $script" >> "$REPORT_FILE"
        echo "Output:" >> "$REPORT_FILE"
        echo "$OUTPUT" >> "$REPORT_FILE"
        echo "" >> "$REPORT_FILE"
    fi
done

# 生成摘要
echo "=========================================" | tee -a "$REPORT_FILE"
echo "Test Summary" | tee -a "$REPORT_FILE"
echo "=========================================" | tee -a "$REPORT_FILE"
echo "Total tests: $TOTAL" | tee -a "$REPORT_FILE"
echo "Passed: $PASSED" | tee -a "$REPORT_FILE"
echo "Failed: $FAILED" | tee -a "$REPORT_FILE"
if [ $TOTAL -gt 0 ]; then
    SUCCESS_RATE=$(( PASSED * 100 / TOTAL ))
    echo "Success rate: ${SUCCESS_RATE}%" | tee -a "$REPORT_FILE"
fi
echo "" | tee -a "$REPORT_FILE"

# 列出失败的测试
if [ ${#FAILED_TESTS[@]} -gt 0 ]; then
    echo "Failed tests (${#FAILED_TESTS[@]}):" | tee -a "$REPORT_FILE"
    for i in "${!FAILED_TESTS[@]}"; do
        echo "  $((i+1)). $(basename "${FAILED_TESTS[$i]}")" | tee -a "$REPORT_FILE"
    done
    echo "" | tee -a "$REPORT_FILE"
fi

echo "Full report saved to: $REPORT_FILE" | tee -a "$REPORT_FILE"

# 保存摘要到单独文件
cat > "$SUMMARY_FILE" << EOF
Test Summary - $(date)
=========================================
Total tests: $TOTAL
Passed: $PASSED
Failed: $FAILED
Success rate: ${SUCCESS_RATE}%

Failed tests:
EOF

if [ ${#FAILED_TESTS[@]} -gt 0 ]; then
    for i in "${!FAILED_TESTS[@]}"; do
        echo "  $((i+1)). $(basename "${FAILED_TESTS[$i]}")" >> "$SUMMARY_FILE"
    done
else
    echo "  None - All tests passed!" >> "$SUMMARY_FILE"
fi

# 显示摘要
echo ""
echo "========================================="
echo "Quick Summary"
echo "========================================="
echo "Total: $TOTAL | Passed: $PASSED | Failed: $FAILED"
if [ $TOTAL -gt 0 ]; then
    echo "Success rate: ${SUCCESS_RATE}%"
fi
echo ""
echo "See detailed report: $REPORT_FILE"
echo "See summary: $SUMMARY_FILE"

# 返回适当的退出码
if [ $FAILED -gt 0 ]; then
    exit 1
else
    exit 0
fi
