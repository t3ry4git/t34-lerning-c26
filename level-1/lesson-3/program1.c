// Some of my personal tests
#include <stdio.h>
#include <stdbool.h> // NOT NEEDED IN C23

int main()
{
    char* name;
    char const* const path_name[[deprecated]] = NULL;
    unsigned const*const a = NULL,b = 0;
    name = NULL;
    bool C23supportedboolean = true;
    printf("%d",C23supportedboolean);
    return 0;
}
