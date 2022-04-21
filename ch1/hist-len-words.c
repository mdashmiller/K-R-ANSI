// Prints a histogram of the lengths of words (1 - 10+) from input

#include <stdio.h>

#define INSIDE  1   // Inside of a word
#define OUTSIDE 0   // Outside of a word
#define MAX     10  // Maximum number of letters to be counted

int main(void)
{
    int c, state, nletters, i, j;
    int lenwords[MAX];          // Length of words from 1 letter to MAX letters

    for (i = 0; i < MAX; ++i)
        lenwords[i] = 0;
    nletters = 0;               // Number of letters in the current word
    state = OUTSIDE;            // Not currently in a word
    while ((c = getchar()) != EOF)
        // If c is not whitespace, count it as a letter
        if (c != ' ' && c != '\t' && c != '\n') {
            ++nletters;
            // If state is outside, switch it to inside
            if (state == OUTSIDE)
                state = INSIDE;
        // When whitespace is found...
        } else {
            // If we had previously been in a word, add the length of the word to
            // the array, reset nletters to 0 and set state to outside of a word
            if (state == INSIDE) {      // Do nothing if still outside of a word
                // Accomodate the MAX letters category
                if (nletters > MAX)
                    nletters = MAX;
                ++lenwords[nletters - 1];
                nletters = 0;
                state = OUTSIDE;
            }
        }

    // Print horizontal histogram
    putchar('\n');
    printf("Word Length | Frequency");
    putchar('\n');
    for (i = 1; i <= MAX; ++i) {
        if (i == MAX)
            printf("%10d+ | ", i);
        else
            printf("%11d | ", i);
        for (j = 0; j < lenwords[i - 1]; ++j)
            putchar('*');
        putchar('\n');
    }

    // Print vertical histogram
    putchar('\n');
    printf("       Frequency\n");
    // Find the highest occuring frequency in lenwords[]
    int hf = 0;
    for (i = 0; i < MAX; ++i)
        if (lenwords[i] > hf)
            hf = lenwords[i];
    // Use hf to build histogram from top down
    for (i = hf; i > 0; --i) {
        printf("%16d |", i);
        for (j = 0; j < MAX; ++j)
            if (lenwords[j] >= i)
                printf("  *  ");
            else
                printf("     ");
        putchar('\n');
    }
    // Add bottom border
    printf("                 +-------------------------------------------------\n");
    // Bottom legend
    printf("Letters per Word ");
    for (i = 1; i <= MAX; ++i) {
        if (i == MAX)
            printf(" %3d+ ", i);
        else
            printf(" %3d ", i);
    }
    putchar('\n');

    return 0;
}