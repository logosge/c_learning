/* Computes the dimensional weight of a box from input provided by the user */

#define INCHES_PER_POUND 166

#include <stdio.h>

int main(void)
{
    int height, length, width, volume, weight;

    printf("Enter height of box: ");
    scanf_s("%d", &height, 5);
    printf("Enter lenght of box: ");
    scanf_s("%d", &length, 5);
    printf("Enter width of box: ");
    scanf_s("%d", &width, 5);
    volume = height * length * width;
    weight = (volume + 165) / INCHES_PER_POUND;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);

    return 0;
}