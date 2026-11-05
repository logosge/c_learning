#include <stdio.h>

int main(void)
{
    int first_num, five_num1, five_num2;
    int first_sum, second_sum, total;

    printf("Enter the first 11 digits of a UPC: ");
    scanf("%1d%5d%5d", &first_num, &five_num1, &five_num2);

    first_sum = first_num + (five_num1 / 1000 % 10) + (five_num1 / 10 % 10) + (five_num2 / 10000) + (five_num2 / 100 % 10) + (five_num2 % 10);
    second_sum = (five_num1 / 10000) + (five_num1 / 100 % 10) + (five_num1 % 10) + (five_num2 / 1000 % 10) + (five_num2 / 10 % 10);

    total = 9 - (((first_sum * 3 + second_sum) - 1) % 10);

    printf("Check digit: %d", total);
    return 0;
}