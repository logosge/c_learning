#include <stdio.h>

int main(void)
{
    double e = 1.0;
    double factorial = 1.0;
    double term = 1.0;
    double epsilon;

    printf("Enter a value for ε: ");
    scanf("%lf", &epsilon);

    for (int i = 1; term > epsilon; i++) {
        factorial *= i;
        e += 1.0 / factorial;
        term = 1.0 / factorial;
    }

    return 0;
}