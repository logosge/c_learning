/* Prints a table of squares using a for statment */

#include <stdio.h>

int main(void)
{
    long n;

    printf("This program prints a tabel of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%ld", &n);


    for (long i = 1; i <= n; i++) {
        printf("%10ld%20ld\n", i, i * i);
    }

    return 0;
}