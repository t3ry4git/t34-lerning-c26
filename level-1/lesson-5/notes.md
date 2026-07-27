# Basic values and data

1. I discovered some strange behavior in the way hexadecimal and binary integer literals are typed. In most cases, it is harmless, but the results can be surprising when a value is close to the minimum or maximum of an integer type.
2. In C23, an enumeration is no longer restricted to an implementation-selected integer type. You can specify a fixed underlying type after a colon: `enum name : type { values... };`.
3. C23 provides more utilities for working with individual bits and bit masks.
4. C23 now provides `__has_include(...)`, a much-needed preprocessing feature.
5. Finally, C23 permits only two's-complement representation for signed integers.
6. `_BitInt` is a cool feature. I did not pay much attention to it at first, but it looks particularly useful for compact values and bit masks that require an exact number of bits.

This lesson was really difficult to read because the chapter contained an enormous amount of information. It also included a lot of mathematics, including some advanced topics. Fortunately, I was already familiar with almost all of it from university. Even so, it was useful to review the material and learn more about the new C23 features.

## Comments from ChatGPT

1. The base of an unsuffixed integer literal affects the list of types considered for it. A decimal literal considers `int`, `long`, and `long long`, whereas a binary, octal, or hexadecimal literal may also select the corresponding unsigned types. For example, on a system with 32-bit `int`, `0x80000000` will commonly have type `unsigned int`, while the decimal literal `2147483648` selects a larger signed type if one can represent it. The unary `-` is a separate operator and is not part of the literal.
2. A C23 enumeration can declare a fixed underlying type, for example `enum status : unsigned char { ready, busy };`. Its enumerator values must be representable by that type. This is valuable when the representation must be stable across interfaces, binary formats, or programming languages. C23 also improves ordinary enumerations without a fixed underlying type by allowing values that are not representable as `int`.
3. The new `<stdbit.h>` header provides type-generic operations on unsigned integer values, including counting leading or trailing zero bits, counting one bits, checking whether a value contains exactly one set bit, and calculating its bit width, bit floor, or bit ceiling. These utilities operate on integer bit patterns; they do not provide a dynamic bit-set container.
4. `__has_include(...)` is a preprocessing operator rather than a normal C function. It can be used in `#if` or `#elif` to test whether a header is available before including it. In `!__has_include(...)`, the `!` is simply the ordinary logical negation operator. GCC and Clang supported similar functionality before C23 as an extension, but C23 standardized it for C.
5. Requiring two's complement removes the sign-and-magnitude and ones'-complement representations, including their negative-zero representations. It does not make signed overflow wrap around: overflowing a signed integer operation still has undefined behavior.
6. `_BitInt(N)` defines a signed bit-precise integer type with a specified width, while `unsigned _BitInt(N)` defines its unsigned counterpart. For example, `unsigned _BitInt(5)` represents values from `0` through `31`. It is not an unlimited arbitrary-precision integer: `N` is fixed at translation time, and each implementation publishes its maximum supported width as `BITINT_MAXWIDTH` in `<limits.h>`.
