/* Contrals seven-segment */

#include <stdio.h>

int main(void)
{
    const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                                 {0, 1, 1, 0, 0, 0, 0},
                                 {1, 1, 0, 1, 1, 0, 0},
                                 };

    double total_temperature = 0;
    double temperature_readings[30][24] = {0};

    for (int i = 0; i < 30; i++) {
        for (int k = 0; k < 24; k++) {
            total_temperature += temperature_readings[i][k];
        }
    }
}