#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("The number %d", number);

    if (number >= 0 && number <= 9)
        printf(" has 1 digit");
    else if (number >= 10 && number <= 99)
        printf(" has 2 digits");
    else if (number >= 100 && number <=999)
        printf(" has 3 digits");
    else if (number >= 1000 && number <= 9999)
        printf(" has 4 digits");
    
    return 0;
}