/* Balances a checkbook */

#include <stdio.h>

int main(void)
{
    float credit_num, debit_num, balance = 0.0f;
    int command;

    printf("*** ACME checkbook-balancing program ***\n");
    printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");

    for (;;) {
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command) {
            case 0:
                balance = 0.0f;
                printf("Balance is clear!");
                break;
            case 1:
                printf("Enter amount of credit: ");
                scanf("%f", &credit_num);
                balance += credit_num;
                break;
            case 2:
                printf("Enter amount of debit: ");
                scanf("%f", &debit_num);
                balance -= debit_num;
                break;
            case 3:
                printf("Current balance: %.2f\n", balance);
                break;
            case 4:
                return 0;
            default:
                printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n");
                break;
        }
    }
}