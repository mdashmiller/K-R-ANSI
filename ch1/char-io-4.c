// Print input one word per line

#include <stdio.h>

#define IN  1       // inside a word
#define OUT 0       // outside a word

int main(void)
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            // Don't insert multiple newlines if there
            // are consecutive whitespace chars
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        } else {
            putchar(c);
            if (state == OUT)
                state = IN;
        }
    }
    return 0;
}