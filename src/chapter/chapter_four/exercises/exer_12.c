#include <stdio.h>

int main(void)
{
    int i = 5;
    int j = ++i * 3 - 2;

    printf("%d %d\n", i, j);

    i = 5;
    j = 3 - 2 * i++;
    printf("%d %d", i, j);

    return 0;
}