/* Enter a U.S. dollar amount and then shows how to pay
 * that amount using the smallest number of $20, $10, $5, and $1 bills */

#include <stdio.h>

int main(void)
{
    int amount;
    int twenty_bills, ten_bills, five_bills, one_bills;

    printf("Enter a U.S. dollar amount: ");
    scanf("%d", &amount);

    twenty_bills = amount / 20;
    ten_bills = (amount - twenty_bills * 20) / 10;
    five_bills = (amount - twenty_bills * 20 - ten_bills * 10) / 5;
    one_bills = amount - twenty_bills * 20 - ten_bills * 10 - five_bills * 5;

    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d\n", twenty_bills, ten_bills, five_bills, one_bills);
    return 0;
}