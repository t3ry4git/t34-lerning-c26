# Expressing computations

Most of the chapter explains the basic principles of arithmetic operations in C, including what happens when a value exceeds the maximum supported by its type. However, I discovered that I had never used the comma as an operator. It is especially interesting because expressions such as `f(a) + g(a)` do not impose an evaluation order on their operands. Function calls have a similar property: C does not specify whether the first or the last argument is evaluated first.

## Comments from ChatGPT

1. Integer overflow does not have one universal behavior in C. Unsigned integer arithmetic wraps modulo one more than the largest value of the type, whereas signed integer overflow has undefined behavior. Conversions and floating-point operations follow their own rules, so “overflow” must always be considered together with the operands' types.
2. Operator precedence and associativity determine how an expression is grouped, not the order in which its operands are evaluated. In `f(a) + g(a)`, the two calls are operands of `+`, but C does not specify which call happens first.
3. The order of function argument evaluation is *unspecified*, not compiler-defined or implementation-defined. The implementation is not required to document or consistently use one order. Code must therefore avoid depending on a particular order, especially when arguments modify the same object.
4. The comma operator introduces sequencing: its left operand is evaluated first, its result is discarded, and then its right operand is evaluated. The value and type of the complete expression come from the right operand.
5. A comma used as a separator is not the comma operator. For example, the commas in `function(a, b)` and `int a, b;` separate syntax elements. Parentheses are commonly needed when the actual comma operator appears in a context where a comma also has a separator meaning.

### Notes about the program

- `<iso646.h>` defines alternative spellings for several operators. In this program, `not_eq` is a macro for `!=`; it does not introduce different comparison semantics.
- `double largeA[N] = {};` uses C23 empty initialization, so every element initially becomes `0.0`. The following loop then overwrites every element with either `0.0` or `1.0`.
- The expression `largeA[i] < 1.0` produces either `0` or `1`, making it suitable as an index into the two-element `sign` array. Here, `sign[1]` counts zero values and `sign[0]` counts values equal to one.
- In `(size_min(1, 2), size_min(3, 4))`, the first call is sequenced before the second, but its result is discarded. The complete expression therefore has the value returned by `size_min(3, 4)`, which is `3`.
- Because the first `size_min` call has no observable side effects, an optimizing compiler may remove it under the as-if rule even though the abstract C semantics evaluate it.
- Reaching the closing brace of `main` is equivalent to returning `0`, so the program reports successful termination without an explicit `return`.
