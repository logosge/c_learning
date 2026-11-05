/* Finds the largest in a series of numbers entered by the user. */

#include <stdio.h>

int main(void)
{
    float num, compare_num;

    printf("Enter numbers one by one: ");
    scanf("%f", &num);
    compare_num = num;

    while (num != 0) {
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num > compare_num) {
            compare_num = num;
        }
    }

    printf("The largest number entered was %.2f.\n", compare_num);

    return 0;
}