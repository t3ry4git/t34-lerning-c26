# Getting started

This was an introductory lesson in which I found:

1. The strange `argv` declaration: `[[maybe_unused]] char* argv[argc+1]`.
   It looks strange, especially `[[maybe_unused]]`. I think it is something like a type specifier for arguments.
2. I cannot remember whether I have used this before, but this syntax exists:

   ```c
   double A[5] = {
       [0] = 9.0,
       [1] = 2.9,
       [4] = 3.E+25,
       [3] = .00007,
   };
   ```

   First of all, I have seen the use of scientific notation for numbers. Second, I cannot remember when I used the `[4] = 1.0` form to specify initialization values in an array.
3. I see the `%g` specifier for `double` for the first time; I have always used `%d`.
4. I think it has always existed, but I have never used it: the `EXIT_SUCCESS` definition in `<stdlib.h>`, which has only one purpose—to write `return 0` in a geeky way.
5. The compilation argument for the new standard was previously `-std=c2x`, where C2x meant C 202x. I searched for some information about this compiler argument, and now it is more correct to write `-std=c23`.

## Comments from ChatGPT

1. `[[maybe_unused]]` is a standard C23 attribute, not a type specifier. It tells the compiler that `argv` may be unused intentionally, which prevents an unused-parameter warning. In a function parameter, the array notation in `argv[argc+1]` is adjusted to a pointer type. The expression also documents that `argv` contains `argc` argument pointers followed by a null pointer.
2. `3.E+25` is scientific notation for `3 × 10²⁵`; similarly, `.00007` could be written as `7.E-5`. The `[index] = value` syntax is called a *designated initializer*. It has been part of C since C99, and elements that are not specified are initialized to zero. Therefore, `A[2]` is `0.0` in `program1.c`.
3. `%g` prints a floating-point value using either decimal or scientific notation, whichever is more compact. `%d` is only for signed integers, so it cannot be used as a replacement for `%g` when the argument is a `double`.
4. `EXIT_SUCCESS` is more than a geeky spelling of `0`: it expresses the intention to report successful program termination and provides a portable success value for the host environment. Returning `0` from `main` also indicates success.
5. `-std=c2x` was the provisional GCC option used while C23 was still being developed. Newer GCC versions accept `-std=c23`, but older versions may still require `-std=c2x` because their C23 support is incomplete.

### Notes about the programs

- `program1.c` includes the required headers and uses `%zu`, which is the correct `printf` conversion specifier for `size_t`.
- `program2.c` is useful as an example of common mistakes: it does not include `<stdio.h>`, declares `main` with the non-standard `void` return type, uses the invalid conversion specifier `%$d`, and returns a value from a `void` function.
- Only four values are supplied for the five-element array in `program2.c`, so `A[4]` is automatically initialized to `0.0`.
