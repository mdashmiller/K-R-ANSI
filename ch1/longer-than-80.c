// Print all input lines that are longer than 80 characters

#include <stdio.h>

#define MAXLINE 1000        // Maximum input line size
#define PRINT   80          // Minumum line size to print

int getline(char line[], int maxline);

int main(void)
{
    int len;                // Current line length
    char line[MAXLINE];     // Current input line

    while ((len = getline(line, MAXLINE)) > 0)
        if ((len - 1) >= PRINT)     // 'len - 1' so that '\0' isn't counted
            printf("%s", line);
    return 0;
}

// Read a line into s, return length
int getline(char s[], int lim)
{
    int c, i;           // The current character and an iterator

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}