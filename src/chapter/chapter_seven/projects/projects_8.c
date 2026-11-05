/* Computes the closest departure time when users enter a time */

#include <stdio.h>

int main(void)
{
    int hour, minute, total_minute;
    int d1 = 8 * 60;
    int d2 = 9 * 60 + 43;
    int d3 = 11 * 60 + 19;
    int d4 = 12 * 60 + 47;
    int d5 = 14 * 60;
    int d6 = 15 * 60 + 45;
    int d7 = 19 * 60;
    int d8 = 21 * 60 + 45;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    total_minute = hour * 60 + minute;

    if (total_minute <= d1) {
        printf("Colsest departure time is 8:00 a.m., arriving at 10:16 a.m.");
    }

    return 0;

}