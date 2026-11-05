#include <stdio.h>

int main(void)
{
    int gs1_prefix, group_identifier, publisher_code, item_number, check_digit;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);

    printf("GS1 prefix: %3d\n"
           "Group identifier: %1d\n"
           "Publisher code: %3d\n"
           "Item number: %5d\n"
           "Check digit: %1d",
           gs1_prefix, group_identifier, publisher_code, item_number, check_digit);

    return 0;
}