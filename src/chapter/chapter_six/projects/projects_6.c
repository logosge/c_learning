#include <stdio.h>

int main(void)
{
    int square = 0, n;
    int count = 2;

    printf("Enter a number n: ");
    scanf("%d", &n);

    while (square < n) {
        square = count * count;
        count++;
        printf("%d\n", square);
    }

    return 0;
}