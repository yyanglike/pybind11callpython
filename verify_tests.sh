#!/bin/bash
# 简单的测试验证脚本

INTERPRETER="./build/run_pys_script"
PASSED=0
FAILED=0

echo "========================================="
echo "Testing New Features"
echo "========================================="
echo ""

test_file() {
    local file=$1
    local name=$2
    echo -n "Testing $name... "
    if $INTERPRETER "$file" > /dev/null 2>&1; then
        echo "✓ PASSED"
        PASSED=$((PASSED + 1))
        return 0
    else
        echo "✗ FAILED"
        FAILED=$((FAILED + 1))
        echo "  Error output:"
        $INTERPRETER "$file" 2>&1 | head -5 | sed 's/^/    /'
        return 1
    fi
}

test_file "python/test_bitwise_operators.pys" "Bitwise Operators"
test_file "python/test_is_not_in.pys" "is/is not/not in"
test_file "python/test_elif.pys" "elif"
test_file "python/test_break_continue.pys" "break/continue"
test_file "python/test_assignment_operators.pys" "Assignment Operators"
test_file "python/test_triple_quotes.pys" "Triple Quotes"
test_file "python/test_nested_comprehension.pys" "Nested Comprehensions"
test_file "python/test_conditional_expression.pys" "Conditional Expression"
test_file "python/test_tuple_literal.pys" "Tuple Literal"
test_file "python/test_all_new_features.pys" "All Features"

echo ""
echo "========================================="
echo "Summary: $PASSED passed, $FAILED failed"
echo "========================================="

if [ $FAILED -eq 0 ]; then
    exit 0
else
    exit 1
fi

