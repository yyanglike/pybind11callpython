#!/bin/bash

# 测试脚本 - 运行所有测试用例并生成报告

INTERPRETER="./build/run_pys_script"
REPORT_FILE="test_report_$(date +%Y%m%d_%H%M%S).txt"

echo "=========================================" > "$REPORT_FILE"
echo "Test Execution Report" >> "$REPORT_FILE"
echo "Date: $(date)" >> "$REPORT_FILE"
echo "=========================================" >> "$REPORT_FILE"
echo "" >> "$REPORT_FILE"

# 检查解释器是否存在
if [ ! -f "$INTERPRETER" ]; then
    echo "ERROR: Interpreter not found at $INTERPRETER" | tee -a "$REPORT_FILE"
    echo "Please build the project first: cmake --build build" | tee -a "$REPORT_FILE"
    exit 1
fi

# 测试用例列表
TEST_SCRIPTS=(
    "python/test_minimal.pys"
    "python/test_simple.pys"
    "python/test_print.pys"
    "python/test_bitwise_operators.pys"
    "python/test_conditional_expression.pys"
    "python/test_tuple_literal.pys"
    "python/test_is_not_in.pys"
    "python/test_elif.pys"
    "python/test_break_continue.pys"
    "python/test_assignment_operators.pys"
    "python/test_triple_quotes.pys"
    "python/test_nested_comprehension.pys"
)

PASSED=0
FAILED=0
TOTAL=0

echo "Running ${#TEST_SCRIPTS[@]} test cases..." | tee -a "$REPORT_FILE"
echo "" >> "$REPORT_FILE"

for script in "${TEST_SCRIPTS[@]}"; do
    TOTAL=$((TOTAL + 1))
    echo "----------------------------------------" | tee -a "$REPORT_FILE"
    echo "[$TOTAL/${#TEST_SCRIPTS[@]}] Testing: $script" | tee -a "$REPORT_FILE"
    echo "----------------------------------------" | tee -a "$REPORT_FILE"
    
    if [ ! -f "$script" ]; then
        echo "✗ FILE NOT FOUND: $script" | tee -a "$REPORT_FILE"
        FAILED=$((FAILED + 1))
        echo "" >> "$REPORT_FILE"
        continue
    fi
    
    # 运行测试并捕获输出
    OUTPUT=$($INTERPRETER "$script" 2>&1)
    EXIT_CODE=$?
    
    echo "$OUTPUT" >> "$REPORT_FILE"
    
    if [ $EXIT_CODE -eq 0 ]; then
        echo "✓ PASSED" | tee -a "$REPORT_FILE"
        PASSED=$((PASSED + 1))
    else
        echo "✗ FAILED (exit code: $EXIT_CODE)" | tee -a "$REPORT_FILE"
        FAILED=$((FAILED + 1))
    fi
    echo "" >> "$REPORT_FILE"
done

echo "=========================================" | tee -a "$REPORT_FILE"
echo "Test Summary" | tee -a "$REPORT_FILE"
echo "=========================================" | tee -a "$REPORT_FILE"
echo "Total tests: $TOTAL" | tee -a "$REPORT_FILE"
echo "Passed: $PASSED" | tee -a "$REPORT_FILE"
echo "Failed: $FAILED" | tee -a "$REPORT_FILE"
echo "Success rate: $(( PASSED * 100 / TOTAL ))%" | tee -a "$REPORT_FILE"
echo "" | tee -a "$REPORT_FILE"
echo "Full report saved to: $REPORT_FILE" | tee -a "$REPORT_FILE"

# 显示报告文件路径
echo ""
echo "Report file: $REPORT_FILE"
cat "$REPORT_FILE"

