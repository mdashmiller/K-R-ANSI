#include <stdio.h>

// Print Fahrenheit -> Celsius table for fahr = 0, 20, ..., 300
// using a call to a funcion outside of main()

#define     LOWER   0       // Lower limit of table
#define     UPPER   300     // Upper limit
#define     STEP    20      // Step size

float convert_to_cel(int f);

int main(void)
{
    int i;      // Iterator

    // Print Fahrenheit to Celsius table
    printf("Fahrenheit\tCelsius\n");
    for (i = LOWER; i <= UPPER; i += STEP)
        printf("%10d\t%7.1f\n", i, convert_to_cel(i));

    return 0;
}

float convert_to_cel(int f)
{
    return (5.0 / 9.0) * (f - 32.0);
}