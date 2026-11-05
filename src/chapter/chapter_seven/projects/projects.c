/* Prints the values of sizeof(type name) */

#include <stdio.h>

int main(void)
{
    printf("%zu %zu %zu %zu", sizeof(int), sizeof(short), sizeof(long long), sizeof(long double));

    return 0;
}