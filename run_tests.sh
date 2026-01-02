#!/bin/bash
set -e

echo "========================================="
echo "Running New Features Tests"
echo "========================================="

INTERPRETER="./build/run_pys_script"
OUTPUT_FILE="test_results.txt"

# Clear output file
> "$OUTPUT_FILE"

# List of test scripts
TEST_SCRIPTS=(
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

PASSED_COUNT=0
FAILED_COUNT=0
FAILED_TESTS=()

for script in "${TEST_SCRIPTS[@]}"; do
    echo "----------------------------------------" | tee -a "$OUTPUT_FILE"
    echo "Testing: $script" | tee -a "$OUTPUT_FILE"
    echo "----------------------------------------" | tee -a "$OUTPUT_FILE"
    
    if $INTERPRETER "$script" 2>&1 | tee -a "$OUTPUT_FILE"; then
        echo "✓ PASSED: $script" | tee -a "$OUTPUT_FILE"
        PASSED_COUNT=$((PASSED_COUNT + 1))
    else
        echo "✗ FAILED: $script" | tee -a "$OUTPUT_FILE"
        FAILED_COUNT=$((FAILED_COUNT + 1))
        FAILED_TESTS+=("$script")
    fi
    echo "" | tee -a "$OUTPUT_FILE"
done

echo "=========================================" | tee -a "$OUTPUT_FILE"
echo "Test Summary" | tee -a "$OUTPUT_FILE"
echo "=========================================" | tee -a "$OUTPUT_FILE"
echo "Total tests: $((PASSED_COUNT + FAILED_COUNT))" | tee -a "$OUTPUT_FILE"
echo "Passed: $PASSED_COUNT" | tee -a "$OUTPUT_FILE"
echo "Failed: $FAILED_COUNT" | tee -a "$OUTPUT_FILE"

if [ $FAILED_COUNT -gt 0 ]; then
    echo "" | tee -a "$OUTPUT_FILE"
    echo "Failed tests:" | tee -a "$OUTPUT_FILE"
    for test in "${FAILED_TESTS[@]}"; do
        echo "  - $test" | tee -a "$OUTPUT_FILE"
    done
    echo "" | tee -a "$OUTPUT_FILE"
    echo "Full test output saved to: $OUTPUT_FILE"
    exit 1
else
    echo "" | tee -a "$OUTPUT_FILE"
    echo "All tests passed!" | tee -a "$OUTPUT_FILE"
    exit 0
fi

