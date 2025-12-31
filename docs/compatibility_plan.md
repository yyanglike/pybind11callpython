# Interpreter Compatibility Plan

## Gaps to close (short term)
- f-strings: currently unsupported and stripped out of tests. Implement parsing/eval or add a pre-pass to convert `f"..."` to `"...".format(...)` when no embedded expressions are used; otherwise support `{expr}` evaluation.
- List/dict/set comprehensions in function bodies: ensure the evaluator can iterate and accumulate without raising “Cannot evaluate” errors.
- Inline unary/relational handling on None: improve expression evaluator to coerce/guard operands.

## Approach
- Add parser support (or a pre-transform) for f-strings, mapping to `format`.
- Extend expression evaluator to create temporary scope and push loop vars for comprehensions; reuse existing for/while evaluation paths to minimize new code.
- Strengthen type guards in unary/relational operations to return ScriptError instead of throwing.

## Regression to add
- f-string happy path: `msg = f"hi {name}"` -> expects `hi world`.
- list comprehension in def body: `[i*i for i in range(3)]` -> `[0,1,4]`.
- Nested indent extraction: function with trailing blank line and dedent after suite.

## Out of scope (later)
- Format specifiers inside f-strings.
- Generator expressions and async constructs.

