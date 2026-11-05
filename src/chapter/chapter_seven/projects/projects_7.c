/* Adds, substracts, multiplies and divides two fraction */

#include <stdio.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char arithmetic_operators = 'A';
    scanf("%d /%d%c%d /%d", &num1, &denom1, &arithmetic_operators, &num2, &denom2);

    switch (arithmetic_operators) {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        default:
            printf("Can't calculate sum.\n");
            return 1;
    }


    printf("The sum is %d/%d\n", result_num, result_denom);

    return 0;
}