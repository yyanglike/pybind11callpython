#!/bin/bash
# 运行全量测试并生成报告

cd "$(dirname "$0")/.."

REPORT_FILE="test_report_full_$(date +%Y%m%d_%H%M%S).txt"

echo "=========================================" | tee "$REPORT_FILE"
echo "Full Test Execution Report" | tee -a "$REPORT_FILE"
echo "Date: $(date)" | tee -a "$REPORT_FILE"
echo "=========================================" | tee -a "$REPORT_FILE"
echo "" | tee -a "$REPORT_FILE"

# 运行全量测试
./scripts/test.sh all --report 2>&1 | tee -a "$REPORT_FILE"

echo "" | tee -a "$REPORT_FILE"
echo "Full report saved to: $REPORT_FILE" | tee -a "$REPORT_FILE"

