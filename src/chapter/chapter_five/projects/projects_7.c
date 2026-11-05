#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    int largest, smallest;
    int max_ab, max_cd, min_ab, min_cd;
    
    printf("Enter four integeers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);

    /* Compare a and b */
    if (a > b) {
        max_ab = a;
        min_ab = b;
    } else {
        max_ab = b;
        min_ab = a;
    }

    /* Compare b and c */
    if (c > d) {
        max_cd = c;
        min_cd = d;
    } else {
        max_cd = d;
        min_cd = c;
    }

    if(min_ab < min_cd) {
        smallest = min_ab;
    } else {
        smallest = min_cd;
    }

    if (max_ab > max_cd) {
        largest = max_ab;
    } else {
        largest = max_cd;
    }

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    return 0;
}