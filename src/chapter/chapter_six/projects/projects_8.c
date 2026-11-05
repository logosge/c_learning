/* Prints a one-month calendar */

#include <stdio.h>

int main(void)
{
    int days_num, start_week;

    printf("Enter number of days in mounth: ");
    scanf("%d", &days_num);
    printf("Enter starting day of the week (1=Sun, 7=sat): ");
    scanf("%d", &start_week);

    for (int c = 1; c < start_week; c++) {
        printf("   ");
    }

    for (int i = 1; i <= days_num; i++) {
        printf("%3d", i);
        if (((start_week - 1 + i) % 7) == 0 || i = days_num)
            printf("\n");
    }

    return 0;

}