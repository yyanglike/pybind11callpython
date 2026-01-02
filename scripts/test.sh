#!/bin/bash
# 统一的测试脚本 - 整合了所有测试功能

set -e

cd "$(dirname "$0")/.."

INTERPRETER="./build/run_pys_script"
MODE="${1:-all}"  # 默认运行所有测试

# 检查解释器是否存在
if [ ! -f "$INTERPRETER" ]; then
    echo "ERROR: Interpreter not found at $INTERPRETER"
    echo "Please build the project first: cmake --build build"
    exit 1
fi

# 显示帮助信息
show_help() {
    cat << EOF
用法: $0 [MODE] [OPTIONS]

测试模式:
  all          - 运行所有测试用例（默认）
  new          - 运行新功能测试
  grammar      - 运行语法修复相关测试
  simple       - 运行简单测试
  list         - 列出所有测试用例
  specific     - 运行指定的测试用例（需要提供文件路径）

选项:
  --report     - 生成详细报告
  --quiet      - 静默模式（只显示摘要）
  --timeout N  - 设置超时时间（秒，默认300，即5分钟）

示例:
  $0                    # 运行所有测试
  $0 new                # 运行新功能测试
  $0 specific python/test_hello.pys  # 运行指定测试
  $0 all --report       # 运行所有测试并生成报告
EOF
}

# 运行单个测试
run_test() {
    local script="$1"
    local quiet="${2:-false}"
    
    if [ ! -f "$script" ]; then
        echo "✗ FILE NOT FOUND: $script"
        return 1
    fi
    
    if [ "$quiet" = "true" ]; then
        if timeout "${TIMEOUT:-300}" $INTERPRETER "$script" > /dev/null 2>&1; then
            return 0
        else
            return 1
        fi
    else
        echo "Testing: $script"
        if timeout "${TIMEOUT:-300}" $INTERPRETER "$script" 2>&1; then
            echo "✓ PASSED: $script"
            return 0
        else
            echo "✗ FAILED: $script"
            return 1
        fi
    fi
}

# 运行所有测试
run_all_tests() {
    local report="${1:-false}"
    local quiet="${2:-false}"
    
    local REPORT_FILE=""
    if [ "$report" = "true" ]; then
        REPORT_FILE="test_report_$(date +%Y%m%d_%H%M%S).txt"
        echo "=========================================" > "$REPORT_FILE"
        echo "Test Execution Report" >> "$REPORT_FILE"
        echo "Date: $(date)" >> "$REPORT_FILE"
        echo "=========================================" >> "$REPORT_FILE"
        echo "" >> "$REPORT_FILE"
    fi
    
    local TEST_SCRIPTS=($(find python -name "*.pys" -type f | sort))
    
    if [ ${#TEST_SCRIPTS[@]} -eq 0 ]; then
        echo "ERROR: No .pys files found in python directory"
        exit 1
    fi
    
    local PASSED=0
    local FAILED=0
    local TOTAL=0
    local FAILED_TESTS=()
    
    if [ "$quiet" != "true" ]; then
        echo "Found ${#TEST_SCRIPTS[@]} test files"
        echo "Running tests..."
        echo ""
    fi
    
    for script in "${TEST_SCRIPTS[@]}"; do
        TOTAL=$((TOTAL + 1))
        script_name=$(basename "$script")
        
        if [ "$quiet" != "true" ] && [ $((TOTAL % 10)) -eq 0 ]; then
            echo "[Progress: $TOTAL/${#TEST_SCRIPTS[@]}]"
        fi
        
        if [ "$report" = "true" ]; then
            echo "----------------------------------------" >> "$REPORT_FILE"
            echo "[$TOTAL/${#TEST_SCRIPTS[@]}] Testing: $script" >> "$REPORT_FILE"
            echo "----------------------------------------" >> "$REPORT_FILE"
        fi
        
        OUTPUT=$(timeout "${TIMEOUT:-300}" $INTERPRETER "$script" 2>&1)
        EXIT_CODE=$?
        
        if [ $EXIT_CODE -eq 0 ]; then
            PASSED=$((PASSED + 1))
            if [ "$report" = "true" ]; then
                echo "[$TOTAL] ✓ $script_name" >> "$REPORT_FILE"
            fi
        else
            FAILED=$((FAILED + 1))
            FAILED_TESTS+=("$script")
            if [ "$report" = "true" ]; then
                echo "[$TOTAL] ✗ FAILED: $script_name (exit code: $EXIT_CODE)" >> "$REPORT_FILE"
                echo "Output:" >> "$REPORT_FILE"
                echo "$OUTPUT" >> "$REPORT_FILE"
                echo "" >> "$REPORT_FILE"
            fi
        fi
    done
    
    # 显示摘要
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
    
    if [ ${#FAILED_TESTS[@]} -gt 0 ]; then
        echo ""
        echo "Failed tests (${#FAILED_TESTS[@]}):"
        for i in "${!FAILED_TESTS[@]}"; do
            echo "  $((i+1)). $(basename "${FAILED_TESTS[$i]}")"
        done
    fi
    
    if [ "$report" = "true" ]; then
        echo ""
        echo "Full report saved to: $REPORT_FILE"
    fi
    
    if [ $FAILED -gt 0 ]; then
        exit 1
    else
        exit 0
    fi
}

# 运行语法修复测试
run_grammar_fixes_tests() {
    local quiet="${1:-false}"
    
    local TEST_SCRIPTS=(
        "python/test_grammar_fixes.pys"
        "python/test_tuple_literal.pys"
        "python/test_assignment_target.pys"
        "python/test_string_literals.pys"
    )
    
    local PASSED=0
    local FAILED=0
    
    if [ "$quiet" != "true" ]; then
        echo "========================================="
        echo "Running Grammar Fixes Tests"
        echo "========================================="
        echo ""
    fi
    
    for script in "${TEST_SCRIPTS[@]}"; do
        if run_test "$script" "$quiet"; then
            PASSED=$((PASSED + 1))
        else
            FAILED=$((FAILED + 1))
        fi
        if [ "$quiet" != "true" ]; then
            echo ""
        fi
    done
    
    echo "========================================="
    echo "Test Summary"
    echo "========================================="
    echo "Total tests: $((PASSED + FAILED))"
    echo "Passed: $PASSED"
    echo "Failed: $FAILED"
    
    if [ $FAILED -gt 0 ]; then
        exit 1
    else
        exit 0
    fi
}

# 运行新功能测试
run_new_features_tests() {
    local quiet="${1:-false}"
    
    local TEST_SCRIPTS=(
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
    
    local PASSED=0
    local FAILED=0
    
    if [ "$quiet" != "true" ]; then
        echo "========================================="
        echo "Running New Features Tests"
        echo "========================================="
        echo ""
    fi
    
    for script in "${TEST_SCRIPTS[@]}"; do
        if run_test "$script" "$quiet"; then
            PASSED=$((PASSED + 1))
        else
            FAILED=$((FAILED + 1))
        fi
        if [ "$quiet" != "true" ]; then
            echo ""
        fi
    done
    
    echo "========================================="
    echo "Test Summary"
    echo "========================================="
    echo "Total tests: $((PASSED + FAILED))"
    echo "Passed: $PASSED"
    echo "Failed: $FAILED"
    
    if [ $FAILED -gt 0 ]; then
        exit 1
    else
        exit 0
    fi
}

# 运行简单测试
run_simple_tests() {
    local TEST_SCRIPTS=(
        "python/test_minimal.pys"
        "python/test_simple.pys"
        "python/test_bitwise_operators.pys"
        "python/test_conditional_expression.pys"
        "python/test_tuple_literal.pys"
    )
    
    local PASSED=0
    local FAILED=0
    
    echo "========================================="
    echo "Running Simple Tests"
    echo "========================================="
    echo ""
    
    for script in "${TEST_SCRIPTS[@]}"; do
        if run_test "$script"; then
            PASSED=$((PASSED + 1))
        else
            FAILED=$((FAILED + 1))
        fi
        echo ""
    done
    
    echo "========================================="
    echo "Test Summary"
    echo "========================================="
    echo "Total: $((PASSED + FAILED))"
    echo "Passed: $PASSED"
    echo "Failed: $FAILED"
    
    if [ $FAILED -gt 0 ]; then
        exit 1
    else
        exit 0
    fi
}

# 列出所有测试用例
list_tests() {
    local TEST_SCRIPTS=($(find python -name "*.pys" -type f | sort))
    
    echo "Found ${#TEST_SCRIPTS[@]} test files:"
    echo ""
    for i in "${!TEST_SCRIPTS[@]}"; do
        printf "%3d. %s\n" $((i+1)) "${TEST_SCRIPTS[$i]}"
    done
}

# 解析参数
REPORT=false
QUIET=false
TIMEOUT=300

while [[ $# -gt 0 ]]; do
    case $1 in
        --help|-h)
            show_help
            exit 0
            ;;
        --report)
            REPORT=true
            shift
            ;;
        --quiet|-q)
            QUIET=true
            shift
            ;;
        --timeout)
            TIMEOUT="$2"
            shift 2
            ;;
        *)
            if [ -z "$MODE_SET" ]; then
                MODE="$1"
                MODE_SET=true
            else
                # 额外的参数作为测试文件
                if [ "$MODE" = "specific" ]; then
                    run_test "$1" "$QUIET"
                    exit $?
                fi
            fi
            shift
            ;;
    esac
done

# 根据模式运行测试
case "$MODE" in
    all)
        run_all_tests "$REPORT" "$QUIET"
        ;;
    new)
        run_new_features_tests "$QUIET"
        ;;
    grammar)
        run_grammar_fixes_tests "$QUIET"
        ;;
    simple)
        run_simple_tests
        ;;
    list)
        list_tests
        ;;
    specific)
        echo "Usage: $0 specific <test_file.pys>"
        exit 1
        ;;
    *)
        echo "Unknown mode: $MODE"
        show_help
        exit 1
        ;;
esac

