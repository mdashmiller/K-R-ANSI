#include <stdio.h>

// Copy text input to output replacing each string
// of one or more blanks with a single blank

int main(void)
{
    int c;                                  // The char we are currently evaluating

    while ((c = getchar()) != EOF) {
        putchar(c);                         // Output the current char
        if (c == ' ') {                     // The current char is a space
           while ((c = getchar()) == ' ')   // Clear the input buffer of any following spaces
                ;
            putchar(c);                     // Ouput the next non-space char
        }
    }
    return 0;
}