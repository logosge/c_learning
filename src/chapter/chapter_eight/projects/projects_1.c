/* Checks numbers for repeated digits */

#include <stdbool.h>
#include <stdio.h>

#define N 10

int main(void)
{
    bool digit_seen[N] = {false}, repeat_contral = false;
    int digit;
    long n;
    int repeat_nums[N] = {0};

    printf("Enter a number: ");
    scanf("%ld", &n);


    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            repeat_nums[digit] = digit;
            repeat_contral = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }


    if (repeat_contral) {
        printf("Repeated digit(s): ");
        for (int i = 0; i < 10; i++) {
            if (repeat_nums[i] != 0)
                printf("%d ", repeat_nums[i]);
        }
    }
    else
        printf("No repeated digit\n");

    return 0;
}