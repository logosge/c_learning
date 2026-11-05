/* Using Horner's Rule to complete polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 */

#include <stdio.h>

int main(void)
{
    double x, result;

    printf("Enter the value of an x: ");
    scanf("%lf", &x);

    result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("The total is: %.2f ", result);

    return 0;
}