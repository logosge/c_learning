#include <stdio.h>

int main(void)
{
    int item_num;
    double unit_pri;
    int month, day, year;

    printf("Enter item number: ");
    scanf("%d", &item_num);

    printf("Enter unit price: ");
    scanf("%lf", &unit_pri);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d /%02d /%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%d\t\t$%.2f\t\t%d%d%d", item_num, unit_pri, month, day, year);

    return 0;
}