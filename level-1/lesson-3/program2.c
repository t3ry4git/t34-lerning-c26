#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

constexpr double eps1m01 = 1.0 - 0x1P-01;
constexpr double eps1p01 = 1.0 + 0x1P-01;
constexpr double eps1m24 = 1.0 - 0x1P-24;
constexpr double eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[argc+1])
{
    for(int i = 1; i < argc; ++i)
    {
        double const a = strtod(argv[i], nullptr);
        double x = 1.0;
        for(;;)
        {
            double prod = a*x;
            if (prod < eps1m01)
                x *= 2.0;
            else if (eps1p01 < prod)
                x*= 0.5;
            else
                break;
        }
        for(;;)
        {
            double prod = a*x;
            if((prod < eps1m24) || (eps1p24 < prod))
                x *= 2.0 - prod;
            else
                break;
        }
        printf("heron: a=%.5e,\tx=%.5e,\ta*x=%.12f\n", a, x, a*x);
    }
    int count = 5;
    // A strange case
    switch(count)
    {
        // int array[count]; VLA - forbidden
        int hh = 11;
        default: puts("+++++++++++++");
        case 4: puts("++++");
        case 3: puts("+++");
        case 2: puts("++");
        case 1: puts("+");
        case 0:
            hh = 20; // This was always possible
        case -1:
            int kk = 20; // Standard in C23; accepted as a C17 extension
                         // unless -pedantic-errors is enabled
    }
    return EXIT_SUCCESS;
}
