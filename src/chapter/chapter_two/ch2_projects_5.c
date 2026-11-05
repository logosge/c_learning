/* Compute polynomial: 3x⁵ + 2x⁴ - 5x³ - x² + 7x - 6 */

#include <stdio.h>

#define CUBED(x) ((x) * (x) * (x))

int main(void)
{
    double x, total;

    printf("Enter the value of an x: ");
    scanf("%lf", &x);

    total = 3 * x * x * CUBED(x) + 2 * CUBED(x) * x - 5 * CUBED(x) - x * x + 7 * x - 6;

    printf("The total is: %.2f ", total);

    return 0;
}