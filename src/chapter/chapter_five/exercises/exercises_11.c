#include <stdio.h>

int main(void)
{
    int area_code;
    printf("Enter area_code: ");
    scanf("%d", &area_code);

    switch (area_code) {
        case 299: 
            printf("Albany");
            break;
        case 404: case 478: case 678: case 770:
            printf("Atlanta");
            break;
        case 706: case 762:
            printf("Savannah");
            break;
        default:
            printf("Area code not recognized");
    }

    return 0;
}