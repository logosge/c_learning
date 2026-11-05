/* Converts a numerical grade into a letter grade */

#include <stdio.h>

int main(void)
{
    int grade;
    int ten_digit;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    ten_digit = grade / 10;

    switch (ten_digit) {
        case 0: case 1: case 2: case 3: case 4: case 5:
            printf("Letter grade: F");
            break;
        case 6:
            printf("Letter grade: D");
            break;
        case 7:
            printf("Letter grade: C");
            break;
        case 8:
            printf("Letter grade: B");
            break;
        case 9: case 10:
            printf("Letter grade: A");
            break;
        default:
            printf("Error: Invalid grade.\n");
    }

    return 0;
}