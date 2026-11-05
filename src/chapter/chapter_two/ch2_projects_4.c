/************************************************************************
 * Name: ch2_projects_4.c                                               *
 * Purpose: Compute a dollars-and-cents amount                          *
 * Author: G. Y. Jian                                                   *
 ************************************************************************/

#include <stdio.h>

#define TAX 0.05
int main(void)
{
    double dollars_cents, total;

    printf("Enter an amount: ");
    scanf_s("%lf", &dollars_cents);

    total = (1.0 + TAX) * dollars_cents;

    printf("With tax added: $%.2f\n", total);

    return 0;
}
