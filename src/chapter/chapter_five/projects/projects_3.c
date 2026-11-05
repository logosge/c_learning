#include <stdio.h>

int main(void)
{
    int shares_num;
    float price_per_share, value;
    float original_commission, rival_commission;

    printf("Enter the number of shares: ");
    scanf("%d", shares_num);
    printf("Enter the price per share: ");
    scanf("%f", &price_per_share);

    value = shares_num * price_per_share;



    /* Original broker commission */
    if (value < 2500.00f)
        original_commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        original_commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        original_commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        original_commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        original_commission = 155.00f + .0011f * value;
    else
        original_commission = 255.00f + .0009f * value;

    if (original_commission < 39.00f)
        original_commission = 39.00f;

    if (value < 2000)
        rival_commission = 33.00f + .003f * value;
    else
        rival_commission = 33.00f + .002f * value;

    printf("Original broker commission: $%.2f\n", original_commission);
    printf("Rival broker commission: $%.2f\n", rival_commission);

}