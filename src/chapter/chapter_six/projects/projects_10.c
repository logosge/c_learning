#include <stdio.h>

int main(void)
{
    int month, year, day;
    int month_re = 0, year_re = 0, day_re = 0;
    int compare_date_1, compare_date_2 = 999999999;

    printf("Enter a date: ");
    scanf("%d /%d /%d", &month, &day, &year);
    compare_date_1 = year * 100000 + month * 1000 + day;
    for (; month != 0 || year != 0 || day != 0;) {
        if (compare_date_1 < compare_date_2) {
            compare_date_2 = compare_date_1;
            month_re = month;
            year_re = year;
            day_re = day;
        }
        printf("Enter a date: ");
        scanf("%d /%d /%d", &month, &day, &year);
        compare_date_1 = year * 100000 + month * 1000 + day;
    }

    printf("%d/%d/%d is the earliest date.", month_re, year_re, day_re);

    return 0;
}