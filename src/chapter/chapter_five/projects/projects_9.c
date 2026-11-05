#include <stdio.h>

int main(void)
{
    int month_first, day_first, year_first;
    int month_second, day_second, year_second;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month_first, &day_first, &year_first);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month_second, &day_second, &year_second);

    if (year_first < year_second) {
        printf("%d/%d/%02d is earlier than %d/%d/%02d",
               month_first, day_first, year_first, month_second, day_second, year_second);
    } else if (year_first > year_second) {
        printf("%d/%d/%02d is earlier than %d/%d/%02d",
               month_second, day_second, year_second, month_first, day_first, year_first);
    } else {  // 年份相等
        if (month_first < month_second) {
            printf("%d/%d/%02d is earlier than %d/%d/%02d",
                   month_first, day_first, year_first, month_second, day_second, year_second);
        } else if (month_first > month_second) {
            printf("%d/%d/%02d is earlier than %d/%d/%02d",
                   month_second, day_second, year_second, month_first, day_first, year_first);
        } else {  // 月份也相等
            if (day_first < day_second) {
                printf("%d/%d/%02d is earlier than %d/%d/%02d",
                       month_first, day_first, year_first, month_second, day_second, year_second);
            } else if (day_first > day_second) {
                printf("%d/%d/%02d is earlier than %d/%d/%02d",
                       month_second, day_second, year_second, month_first, day_first, year_first);
            } else {
                printf("Both dates are the same: %d/%d/%02d",
                       month_first, day_first, year_first);
            }
        }
    }

    return 0;
}