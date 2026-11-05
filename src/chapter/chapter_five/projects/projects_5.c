/* Compute income tax for single residents */

#include <stdio.h>

int main(void)
{
    float income;
    float tax_due;

    printf("Enter your income: ");
    scanf("%f", &income);

    if (income < 0) {
        printf("Income can't be negative.\n")
    }

    if (income < 750.00f) {
        tax_due = income * .01f;
    } else if (income <= 2250.00f) {
        tax_due = 7.50f + (income - 750.00f) * .02f; 
    } else if (income <= 3750.00f) {
        tax_due = 37.50f + (income - 2250.00f) * .03f;
    } else if (income <= 5250.00f) {
        tax_due = 82.50f + (income - 3750.00f) * .04f;
    } else if (income <= 7000.00f) {
        tax_due = 142.50f + (income - 5250.00f) * .05f;
    } else {
        tax_due = 230.00f + (income - 7000.00f) * .06f;
    } 

    printf("The tax due of $%.2f is: %.2f", income, tax_due);

    return 0;

}