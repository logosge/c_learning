#include <stdio.h>

int main(void)
{
    int gcd, numerator_t, denominator_t;
    int numerator, denominator, r;

    printf("Enter a fraction: ");
    scanf("%d /%d", &numerator, &denominator);

    numerator_t = numerator;
    denominator_t = denominator;

    while (denominator_t != 0) {
        r = numerator_t % denominator_t;
        numerator_t = denominator_t;
        denominator_t = r;
    }

    gcd = numerator_t;

    printf("Greatest common divisor: %d\n", gcd);

    printf("In lowest terms: %d/%d", numerator / gcd, denominator / gcd);

    return 0;
}