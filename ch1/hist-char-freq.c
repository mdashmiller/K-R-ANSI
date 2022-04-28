// Prints a histogram of the frequencies of different
// non-whitespace characters from input
#include <stdio.h>

#define NCHARS  94          // The number of printable characters excluding SPACE

int main(void)
{
    int c;                  // The current char we are evaluating
    int i, j, f;            // Two interators and a counter
    int ctypes[NCHARS];     // Each index represents a unique printable char

    for (i = 0; i < NCHARS; ++i)
        ctypes[i] = 0;

    while ((c = getchar()) != EOF)
        // For each value of c, convert it from 32 - 126 to
        // 0 - 94 and increment the value at the appropriate index
        ++ctypes[c - '!'];

    // Print horizontal histogram
    putchar('\n');
    for (i = '!'; i < ('!' + NCHARS); ++i) {
        printf("%c", i);
        putchar(' ');
        putchar('|');
        putchar(' ');
        for (j = 0; j < ctypes[i - '!']; ++j)
            putchar('*');
        putchar('\n');
    }

    // Print vertical histogram
    putchar('\n');
    // Find the value of the highest frequency of occurance
    f = 0;
    for (i = 0; i < NCHARS; ++i)
        if (ctypes[i] > f)
            f = ctypes[i];
    // Use f to build histogram from top down
    for(; f > 0; --f) {
        printf("%2i | ", f);
        for (i = 0; i < NCHARS; ++i)
            if (ctypes[i] >= f)
                putchar('*');
            else
                putchar(' ');
        if (f != 1)
            putchar('\n');
    }
    // Print bottom legend
    printf("\n   +");
    for (i = 0; i < NCHARS; ++i)
        printf("-");
    putchar('\n');
    printf("     ");
    for(i = '!'; i < NCHARS; ++i)
        printf("%c", i);
    putchar('\n');

    return 0;
}