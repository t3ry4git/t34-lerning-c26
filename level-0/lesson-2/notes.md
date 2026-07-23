# The principal structure of a program

The lesson covered the basics of C grammar, semantics, and related topics. I did not encounter anything new or any interesting blocks of code, so I dug deeper into the `_Generic` construct and ways of passing arrays in C23.

Unlike C++, C23 does not have templates. It relies on language features such as `_Generic` and macros when a programmer needs to write generic functions that work with arrays of different types, including arrays of complex structures.

I assume that the next part of the book will be more complicated. From what I can see, the next chapters cover expressions, semantics, and data structures. These are fundamental concepts in C, and I expect this to be the hardest part of the book because much of the information may be boring to me, while only small details may catch my interest.

I also recalled that empty braces, `{}`, perform zero initialization. This is important to remember. I was not sure whether `{}` worked the same way in earlier versions of C.

## Comments from ChatGPT

1. `_Generic` is not a macro; it is a C language construct called a *generic selection*. It chooses an expression according to the type of another expression. It is often placed inside a macro to create an interface that behaves like a generic function.
2. C does not pass an entire array to a function by value. In most expressions, including function calls, an array is converted to a pointer to its first element. The function therefore usually needs a separate length argument. An array parameter may also use `static` to document a minimum required length, for example `void process(size_t n, int values[static n])`.
3. `_Generic` can dispatch to different functions based on an argument's type, but every selected function still needs an appropriate declared parameter type. It does not provide templates or create new function implementations automatically as C++ templates do.
4. Empty initialization with `{}` was standardized in C23. It performs *empty initialization*, which initializes scalar values to zero and recursively initializes aggregate members or array elements as if they had static storage duration. For earlier C standards, `{0}` is the portable way to zero-initialize an object; some compilers accepted `{}` as an extension.
