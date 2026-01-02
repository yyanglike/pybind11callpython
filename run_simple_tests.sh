#!/bin/bash

echo "========================================="
echo "Running Test Cases"
echo "========================================="

INTERPRETER="./build/run_pys_script"

# Test scripts to run
TEST_SCRIPTS=(
    "python/test_minimal.pys"
    "python/test_simple.pys"
    "python/test_bitwise_operators.pys"
    "python/test_conditional_expression.pys"
    "python/test_tuple_literal.pys"
)

PASSED=0
FAILED=0

for script in "${TEST_SCRIPTS[@]}"; do
    echo ""
    echo "----------------------------------------"
    echo "Testing: $script"
    echo "----------------------------------------"
    
    if [ -f "$script" ]; then
        if $INTERPRETER "$script" 2>&1; then
            echo "✓ PASSED: $script"
            PASSED=$((PASSED + 1))
        else
            echo "✗ FAILED: $script"
            FAILED=$((FAILED + 1))
        fi
    else
        echo "✗ FILE NOT FOUND: $script"
        FAILED=$((FAILED + 1))
    fi
done

echo ""
echo "========================================="
echo "Test Summary"
echo "========================================="
echo "Total: $((PASSED + FAILED))"
echo "Passed: $PASSED"
echo "Failed: $FAILED"

