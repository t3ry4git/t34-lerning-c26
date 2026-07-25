#define N 10
#include <stdlib.h>
#include <iso646.h> // For fancy operator spellings
#include <stdio.h>

size_t size_min(size_t a, size_t b)
{
    return (a < b) ? a : b;
}

int main(){
    double largeA[N] = { };
    for(size_t i = 0; i < N; i++)
    {
        largeA[i]=rand()%2;
    }

    size_t sign[2] = { 0, 0 };

    for (size_t i = 0; i < N; ++i) {
        sign[(largeA[i] < 1.0)] += 1;
        if(sign[0] not_eq sign[1])
            puts("not_eq is fancy");
    }
    // The left result is discarded, so the comma expression yields size_min(3, 4)
    size_t interesting_moment = (size_min(1,2), size_min(3,4));
    printf("interesting=%zu\n", interesting_moment);
}
