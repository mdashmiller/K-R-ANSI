#include <stdio.h>

// Print Celsius -> Fahrenheit table
// for celsius = 0, 20, ..., 300

int main(void)
{
    int celsius, fahr;
    int lower, upper, step;

    lower = 0;      // Lower limit of temp table
    upper = 300;    // Upper limit
    step = 20;      // Step size

    // Table heading
    printf("Celsius\tFahrenheit\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0 * celsius) + 32;
        printf("%7d\t%10d\n", celsius, fahr);
        celsius += step;
    }
}