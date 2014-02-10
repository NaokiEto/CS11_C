#include <stdio.h>

/* This prints hello, *your name* */
int main(void)
{
    char s[100];  /* N.B. strings are arrays of chars in C */

    printf("Please enter your name: ");
    scanf("%99s", s);

    printf("hello, %s \n", s);
    return 0;
}
