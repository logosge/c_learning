#include <stdio.h>

#define PRE_OCTAL 0

int main(void)
{
    int decimal_num;

    int octal_n1, octal_n2, octal_n3, octal_n4;

    printf("Enter a number between 0 and 32767: ");
    scanf("%5d", &decimal_num);

    octal_n1 = decimal_num % 8;
    octal_n2 = decimal_num / 8 % 8;
    octal_n3 = decimal_num / 8 / 8 % 8;
    octal_n4 = decimal_num / 8 / 8 / 8 % 8;

    printf("In octal, your number is : %d%d%d%d%d", PRE_OCTAL, octal_n4, octal_n3, octal_n2, octal_n1);

    return 0;
}