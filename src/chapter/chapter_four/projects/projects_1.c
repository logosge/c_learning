/* Complete the programming project in the chapter for */

#include <stdio.h>

#define HUNDRED_CONSTANT 100
#define TEN_CONSTANT 10

int main(void)
{
    int digit;
    int reversed_digit = 0;
    int reminder;
    int quotient;

    printf("Enter a number: ");
    scanf("%d", &digit);


    do {
        reminder = digit % TEN_CONSTANT;
        digit /= TEN_CONSTANT;
        reversed_digit = reversed_digit * TEN_CONSTANT + reminder;
    } while (digit);
    


    printf("The reversal is %d", reversed_digit);
    return 0;
}
