#include <stdio.h>

int main(void)
{
    int hour, minutes, since_mid_minutes;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minutes);

    since_mid_minutes = hour * 60 + minutes;

    int d1 = 8 * 60;
    int d2 = 9 * 60 + 43;
    int d3 = 11 * 60 + 19;
    int d4 = 12 * 60 + 47;
    int d5 = 14 * 60;
    int d6 = 15 * 60 + 45;
    int d7 = 19 * 60;
    int d8 = 21 * 60 + 45;
    
    /* if (since_mid_minutes < (d1 + d2) / 2) {
        printf("Closet departure time is 8:00 a.m., arriving at 10:16 a.m.");
    } else if (since_mid_minutes < (d2 + d3) / 2) {
        printf("Closet departure time is 9:43 a.m., arriving at 11:52 a.m.");
    } else if (since_mid_minutes < (d3 + d4) / 2) {
        printf("Closet departure time is 11:19 a.m., arriving at 13:31 a.m.");
    } else if (since_mid_minutes < (d4 + d5) / 2) {
        printf("Closet departure time is 12:47 p.m., arriving at 03:00 p.m.");
    } else if (since_mid_minutes < (d5 + d6) / 2) {
        printf("Closet departure time is 02:00 p.m., arriving at 04:08 p.m.");
    } else if (since_mid_minutes < (d6 + d7) / 2) {
        printf("Closet departure time is 03:45 p.m., arriving at 05:55 p.m.");
    } else if (since_mid_minutes < (d7 + d8) / 2) {
        printf("Closet departure time is 07:00 p.m., arriving at 09:20 p.m.");
    } else {
        printf("Closet departure time is 09:45 p.m., arriving at 11:58 a.m.");
    } */
    
    if (since_mid_minutes <= d1) {
        printf("Closet departure time is 8:00 a.m., arriving at 10:16 a.m.");
    } else if (since_mid_minutes <= d2) {
        if (since_mid_minutes - d1 < d2 - since_mid_minutes) {
            printf("Closet departure time is 8:00 a.m., arriving at 10:16 a.m.");
        } else {
            printf("Closet departure time is 9:43 a.m., arriving at 11:52 a.m.");
        }
    } else if (since_mid_minutes <= d3) {
        if (since_mid_minutes - d2 < d3 - since_mid_minutes) {
            printf("Closet departure time is 9:43 a.m., arriving at 11:52 a.m.");
        } else {
            printf("Closet departure time is 11:19 a.m., arriving at 13:31 a.m.");
        }
    }

    return 0;
}