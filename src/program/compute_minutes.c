#include <stdio.h>

int main(void)
{
    int d1, h1, m1;
    int d2, h2, m2;
    int total1, total2, diff;

    printf("Enter first time (day hour minute): ");
    scanf("%d %d %d", &d1, &h1, &m1);

    printf("Enter second time (day hour minute): ");
    scanf("%d %d %d", &d2, &h2, &m2);

    total1 = d1 * 1440 + h1 * 60 + m1;
    total2 = d2 * 1440 + h2 * 60 + m2;

    if (total1 > total2)
        diff = total1 - total2;
    else
        diff = total2 - total1;

    printf("\nDifference: %d minutes\n", diff);

    return 0;
}