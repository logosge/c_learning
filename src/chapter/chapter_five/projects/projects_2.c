#include <stdio.h>

int main(void)
{
    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    printf("Equivalent 12-hour time: ");

    switch (hour){
        case 0: printf("12:%02d AM\n", minute); break;
        case 12: printf("12:%02d PM\n", minute); break;
        case 13: printf("1:%02d PM\n", minute); break;
        case 14: printf("2:%02d PM\n", minute); break;
        case 15: printf("3:%02d PM\n", minute); break;
        case 16: printf("4:%02d PM\n", minute); break;
        case 17: printf("5:%02d PM\n", minute); break;
        case 18: printf("6:%02d PM\n", minute); break;
        case 19: printf("7:%02d PM\n", minute); break;
        case 20: printf("8:%02d PM\n", minute); break;
        case 21: printf("9:%02d PM\n", minute); break;
        case 22: printf("10:%02d PM\n", minute); break;
        case 23: printf("11:%02d PM\n", minute); break;
        case 24: printf("12:%02d PM\n", minute); break;
        default: printf("%d:%02d AM\n", hour, minute); break;
    }

    return 0;
}