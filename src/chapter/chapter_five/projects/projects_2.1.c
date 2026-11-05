#include <stdio.h>

int main(void)
{
    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    printf("Equivalent 12-hour time: ");

    if (hour == 0) {
        printf("12:%02d AM\n", minute);
    } else if (hour >= 1 && hour <= 11) {
        printf("%d:%02d AM", hour, minute);
    } else if (hour >= 13 && hour <= 23) {
        printf("%d:%02d PM", hour - 12, minute);
    } else if (hour == 24) {
        printf("%d:%02d PM", hour - 12);
    }

    return 0;
}