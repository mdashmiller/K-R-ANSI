#include <stdio.h>

// Count blanks, tabs and newlines from
// text input

int main(void)
{
    int c;              // char being evaluated
    int b, t, nl;       // blanks, tabs, and newlines

    b = t = nl = 0;     // initialize all counters at 0
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++b;
        if (c == '\t')
            ++t;
        if (c == '\n')
            ++nl;
    }

    printf("blanks: %d, tabs: %d, newlines: %d\n", b, t, nl);
    return 0;
}