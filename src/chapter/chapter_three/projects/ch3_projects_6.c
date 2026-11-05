#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
    int row1, row2, row3, row4;
    int col1, col2, col3, col4;
    int diag1, diag2;

    printf("Enter the numbers from 1 to 16 in any order: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o, &p);

    printf("\n%3d %3d %3d %3d\n", a, b, c, d);
    printf("%3d %3d %3d %3d\n", e, f, g, h);
    printf("%3d %3d %3d %3d\n", i, j, k, l);
    printf("%3d %3d %3d %3d\n", m, n, o, p);

    row1 = a + b + c + d;
    row2 = e + f + g + h;
    row3 = i + j + k + l;
    row4 = m + n + o + p;

    col1 = a + e + i + m;
    col2 = b + f + j + n;
    col3 = c + g + k + o;
    col4 = d + h + l + p;

    diag1 = a + f + k + p;
    diag2 = d + g + j + m;

    printf("\nRow sums: %d %d %d %d\n", row1, row2, row3, row4);
    printf("Column sums: %d %d %d %d\n", col1, col2, col3, col4);
    printf("Diagonal sums: %d %d\n", diag1, diag2);

    return 0;
}