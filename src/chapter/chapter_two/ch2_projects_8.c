/* Calculates the remaining balance on a loan after the first, second, and third monthly payments */

#include <stdio.h>

int main(void)
{
    double loan_amount, interest_rate, month_rate, payment;
    double first_payment, second_payment, third_payment;

    printf("Enter amount of loan: ");
    scanf_s("%lf", &loan_amount);

    printf("Enter interest rate: ");
    scanf_s("%lf", &interest_rate);

    printf("Enter monthly payment: ");
    scanf_s("%lf", &payment);

    month_rate = interest_rate / 100 / 12.0;

    first_payment = (loan_amount - payment) + loan_amount * month_rate;
    second_payment = (first_payment - payment) + first_payment * month_rate;
    third_payment = (second_payment - payment) + second_payment * month_rate;

    printf("Balance remaining after first payment: $%.2f\n", first_payment);
    printf("Balance remaining after second payment: $%.2f\n", second_payment);
    printf("Balance remaining after third payment: $%.2f\n", third_payment);

    return 0;
}