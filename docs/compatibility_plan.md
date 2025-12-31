# Interpreter Compatibility Plan (updated)

## Current status (done)
- f-strings：预处理支持单/双/三引号，多行，格式说明符（如 `:0>6.2f`），通过 `__fstr__` + `py::eval`，注入当前变量/模块作用域。未闭合时保留尾部文本避免截断。
- 推导式：list/dict/set 使用 C++ 显式循环求值，无 eval。
- 生成器表达式：用 Python 辅助生成器 `__gen_map__` 包装 C++ 回调，保持惰性且无 eval。
- sys.argv：运行前统一初始化为非空 list，避免 None/长度为 0。
- 函数体提取：基于行缩进扫描，包含尾部空行/DEDENT，避免截断。

## Remaining gaps / risks
- 表达式求值在 None 参与的比较/一元运算的防护可再加强。
- 错误映射：f-string 或 eval 抛出的 Python 语法/运行时错误未带精确源位置信息。
- 多线程：单实例非线程安全；进入 Python 必须持有 GIL，需各线程独立解释器实例或显式加锁。

## Next steps (optional)
- 强化 None 相关一元/关系运算的类型保护，给出更清晰的脚本错误。
- 提升错误位置信息：在 f-string 预处理和生成器辅助中记录原始偏移并回填到报错。
- 若需要并发：文档化 GIL 使用策略（每线程一实例，`gil_scoped_acquire`/`release` 包裹重计算段），评估 per-interpreter GIL（PEP 684）可行性。

## Regression coverage（已有/可补充）
- f-string：基本插值、多行三引号、格式说明符。
- 推导式：list/dict/set 正常求值。
- 生成器：惰性迭代、`__next__` 调用。
- 缩进：带尾部空行的函数体提取。

