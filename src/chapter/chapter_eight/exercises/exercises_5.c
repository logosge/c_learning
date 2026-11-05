/* Solves the fifth exercise */

#include <stdio.h>

int main(void)
{
    long long fib_numbers[40] = {0};  // Saves the first 40 Fibonacci numbers

    /*Fill in the first two numbers individually. */
    fib_numbers[0] = 0;
    fib_numbers[1] = 1;    

    /*Use a loop to compute the remaining numbers */
    for (int i = 2; i < 40; i++) {
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
    }

    /* Print the whole array */
    for (int i = 0; i < 40; i++) {
        if ((i % 10) == 0 && i != 0)
            printf("\n");
        printf("%10lld ", fib_numbers[i]);
    }
    
    return 0;

}