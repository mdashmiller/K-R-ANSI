// Print the length of the longest line and as much of its text as possible
// from input

#include <stdio.h>

#define MAXLINE 1000    // Maximum input line size

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(void)
{
    int len;            // Current line length
    int max;            // Maximum length seen so far
    char line[MAXLINE];     // Current input line
    char longest[MAXLINE];  // Longest line saved here

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {      // There was a line
        printf("Longest line: %s", longest);
        printf("Number of characters: %d\n", max - 1);  // Don't count '\0' as a character
    }
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

// Copy 'from' into 'to'; assume 'to' is big enough
void copy(char to[], char from[])
{
    int i;       // An iterator

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}