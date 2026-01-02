#!/bin/bash

# 测试所有新功能的脚本

echo "=========================================="
echo "Testing New Grammar Features"
echo "=========================================="
echo ""

TESTS=(
    "python/test_bitwise_operators.pys"
    "python/test_is_not_in.pys"
    "python/test_elif.pys"
    "python/test_break_continue.pys"
    "python/test_assignment_operators.pys"
    "python/test_triple_quotes.pys"
    "python/test_nested_comprehension.pys"
    "python/test_conditional_expression.pys"
    "python/test_tuple_literal.pys"
    "python/test_all_new_features.pys"
)

PASSED=0
FAILED=0

for test in "${TESTS[@]}"; do
    echo "Running: $test"
    if ./build/run_pys_script "$test" 2>&1; then
        echo "✓ PASSED: $test"
        ((PASSED++))
    else
        echo "✗ FAILED: $test"
        ((FAILED++))
    fi
    echo ""
done

echo "=========================================="
echo "Test Summary:"
echo "  Passed: $PASSED"
echo "  Failed: $FAILED"
echo "  Total:  $((PASSED + FAILED))"
echo "=========================================="

if [ $FAILED -eq 0 ]; then
    exit 0
else
    exit 1
fi

