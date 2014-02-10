/*
 * easter.c calculates the date of Easter given an input year.
 * This is found using an algorithm from Donald Knuth's book
 * The Art of Computer Programming.
 */

#include <stdio.h>

/* This function calculates the Easter date given an input year.
 * The argument is an integer input year between 1582 and 39999.
 * If the argument is outside of these bounds, a 0 is returned.
 * If the argument is within these bounds, then a date that is
 * positive will be outputted if the month of Easter is April,
 * and the date that is negative will be outputted if the month
 * of Easter is March.
 */
int calculate_Easter_date(int inputyear)
{
    int goldenyr, century, leapyr, mooncorrect, sunday, epact, fullmoon;

    if (inputyear < 1582 || inputyear > 39999)
    {
        return 0;
    }

    /* the "golden year" in the 19-year Metonic cycle. */
    goldenyr = (inputyear % 19) + 1;

    /* century of the year inputted */
    century = (inputyear / 100) + 1;

    /* The skipped leap years */
    leapyr = (3 * century / 4) - 12;

    /* A correction factor for the moon's orbit */
    mooncorrect = ((8 * century + 5) / 25) - 5;

    /* March ((-sunday) mod 7 + 7) is a Sunday. */
    sunday = (5 * inputyear / 4) - leapyr - 10;

    /* the "epact" which specifies when a full moon occurs. */
    epact = (11 * goldenyr + 20 + mooncorrect - leapyr) % 30;

    if ((epact == 25 && goldenyr > 11) || epact == 24)
    {
        epact += 1;
    }

    /* March fullmoon is a "calendar full moon". */
    fullmoon = 44 - epact;

    if (fullmoon < 21)
    {
        fullmoon += 30;
    }

    fullmoon = fullmoon + 7 - ((sunday + fullmoon) % 7);

    /* date for April  */
    if (fullmoon > 31)
    {
        fullmoon -= 31;
    }
    /* date for March (negative) */
    else
    {
        fullmoon *= -1;
    }
    return fullmoon;
}

/* Here, the calculate_Easter_date function is used. We read the years
 * from a file, and output the Easter date with the year in a separate
 * output file 
 */
int main(void)
{
    int year, date;

    while(1)
    {
        /* Return value of scanf to help determine end of file */
        int result;

        /* the year for which the date of Easter is to be determined. */
        result = scanf("%d", &year);

        /* if we reach the end of the file, go out of while loop */
        if (result == EOF)
        {
            break;
        }

        date = calculate_Easter_date(year);
        
        /* Print out the year, month, and day */
        if (date > 0)
        {
            printf("%d - April %d\n", year, date);
        }
        else if (date == 0)
        {
            fprintf(stderr, "The year is not between 1582 and 39999!\n");
        }
        else
        {
            printf("%d - March %d\n", year, -1 * date);
        }
    }

    return 0;
}
