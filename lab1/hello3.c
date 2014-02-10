#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This chooses a random number in the range [1, 10]
 * If the number # is even, "# hello, *your name*" is
 * printed that amount of times. If the number # is
 * odd, "# hi, *your name*" is printed that amount of 
 * times.
*/
int main(void)
{
    char s[100];  /* N.B. strings are arrays of chars in C */

    /* random number */
    int r;

    /* index for the for loop later on */
    int idx;

    /* the seed for the random number generator */
    srand(time(0));

    printf("Please enter your name: ");
    scanf("%99s", s);

    /* calculate random number in range [1, 10] */
    r = rand()%10 + 1;

    for (idx = 0; idx < r; idx++)
    {
        if (r%2 == 0)
        {
            printf("%d hello, %s \n", r, s);
        }
        else
        {
            printf("%d hi, %s \n", r, s);
        }
    }
    return 0;
}
