#include <stdio.h>

int main(void)
{
    int speed;

    printf("Enter a wind speed(in knots): ");
    scanf("%d", &speed);

    if (speed < 1)
        printf("The wind speed is calm.");
    else if (speed >= 1 && speed <= 3)
        printf("The wind speed is light air.");
    else if (speed >= 4 && speed <= 27)
        printf("The wind speed is breeze.");
    else if (speed >= 28 && speed <= 47)
        printf("The wind speed is gale.");
    else if (speed >= 48 && speed <= 63)
        printf("The wind speed is storm.");
    else 
        printf("The wind speed is hurricane.");

    return 0;
}