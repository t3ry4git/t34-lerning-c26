# Buckle up

1. Previously, I had serious trouble determining how type attributes, qualifiers, and modifiers bind in declarations. After attending a few interviews, I finally learned the principle of left binding. It is good that the book mentions this principle.
2. One interesting declaration is `unsigned const * const a, b;`. Here, `*` belongs only to `a`, so `a` has the type `unsigned const * const`, whereas `b` has the type `unsigned const`. This works because `*` is part of the declarator associated with the nearest identifier:

   ```text
   unsigned const int (* <- a) <- const
   ```

   Therefore, the complete type of `a` is `unsigned const int * const`.
3. C23 introduces digit separators. It is not a huge feature, but it is a nice one.

## Comments from ChatGPT

1. A C declaration consists of shared declaration specifiers followed by one or more comma-separated declarators. Reading a declarator outward from its identifier is more reliable than treating the entire text to the left as one indivisible type.
2. In `unsigned const * const a, b;`, the shared declaration specifiers are `unsigned const`, which is another spelling of `const unsigned int`. The declarator `* const a` makes `a` a constant pointer to a constant unsigned integer. The declarator for `b` contains no `*`, so `b` is simply a constant unsigned integer. To declare two constant pointers, each declarator needs its own `* const`.
3. C23 allows an apostrophe to separate digits in numeric literals, for example `1'000'000`, `0xFF'00`, and `0b1010'0101`. Separators improve readability but do not affect the value or type of a literal.

# Everything is about control

1. The `bool` type is finally available in C23 without including `<stdbool.h>`.
2. I have never used `constexpr` before. It is a new C23 feature for defining compile-time constant objects. One reason for its existence is to avoid macros such as `#define SOME_VALUE 10` when a typed, addressable constant is needed.
3. `nullptr` is another new C23 keyword. It provides an unambiguous null pointer constant instead of relying on definitions such as `#define NULL 0`. The corresponding `nullptr_t` type is available from `<stddef.h>`.
4. I found some interesting details about `case` labels, particularly how they interact with declarations and with variables initialized before or after a label.

## Comments from ChatGPT

1. C has had the built-in Boolean type `_Bool` since C99. C23 additionally makes `bool`, `true`, and `false` language keywords, so `<stdbool.h>` is no longer required to obtain those names.
2. A C23 `constexpr` object is implicitly `const`, must have an initializer that satisfies the constant-expression rules, and can itself be used in constant-expression contexts. Unlike C++, C23 does not support `constexpr` functions.
3. The `nullptr` keyword can be used without including a header. `<stddef.h>` is required only when the name `nullptr_t` is used explicitly. Unlike a traditional `NULL` macro that may expand to integer zero, `nullptr` has a distinct type and cannot accidentally be used as an ordinary integer.
4. A `switch` transfers control directly to the matching `case` or `default` label. It can therefore skip an earlier initializer even though the variable's name is in scope after its declaration. Skipping an ordinary declaration is allowed, but the object must be assigned a value before it is read. Jumping into the scope of a variably modified type, such as a VLA, is prohibited.
5. Before C23, a label had to be followed by a statement, and a declaration is not a statement in C. C23 permits a label directly before a declaration. GCC and Clang may accept this syntax in C17 mode as an extension, but strict compilation with `-pedantic-errors` rejects it.

### Notes about the programs

- In `program1.c`, `<stdbool.h>` is unnecessary when compiling as C23, although including it is harmless. `NULL` could be replaced with `nullptr` to make the null pointer values explicit.
- The declaration `unsigned const * const a = NULL, b = 0;` gives `a` and `b` different types: `a` is a constant pointer to a constant unsigned integer, while `b` is a constant unsigned integer.
- In `program2.c`, `strtod(argv[i], nullptr)` discards the end-pointer result. The `<stddef.h>` header is not required solely for the `nullptr` keyword.
- The initializer `int hh = 11;` is never executed because every entry into the `switch` jumps directly to a label below it. The later assignment `hh = 20;` is valid because it writes a value instead of reading the skipped initial value.
- The declaration immediately after `case -1:` is standard C23 syntax. In C17, a portable spelling is `case -1: { int kk = 20; /* ... */ }`.
- The missing `break` statements cause intentional fallthrough: execution continues through every subsequent case until it reaches the end of the `switch`.
- A `case` label does not create a scope of its own. Braces are needed when a case should have local variables that are isolated from the rest of the `switch`.
