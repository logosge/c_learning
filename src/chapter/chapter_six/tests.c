#include <stdio.h>

int main(void)
{
    int d, prime_num;

    printf("Enter a number: ");
    scanf("%d", &prime_num);

    for (d = 2; d * d < prime_num; d++) {
        if (prime_num % d == 0) {
            break;
        }
    }

    if (d * d < prime_num) {
        printf("%d is divisible by %d\n", prime_num, d);
    } else {
        printf("%d is prime\n", prime_num);
    }
    

    return 0;
}