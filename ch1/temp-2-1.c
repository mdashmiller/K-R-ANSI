#include <stdio.h>

// Print Fahrenheit -> Celsius table
// for fahr = 0, 20, ..., 300

#define     LOWER   0       // Lower limit of table
#define     UPPER   300     // Upper limit
#define     STEP    20      // Step size

int main(void)
{
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
    return 0;
}