/*
 * sorter.c takes in as many as 32 integers to sort as command line 
 * arguments. It sorts the integers, and prints the result to the console. 
 * If the optional command line argument -b is used, then use bubble_sort. 
 * If -b is not used, then use minimum_sort. If the optional command line 
 * argument -q is used, then do not print the result to the console.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NUMBERS 32 /* Maximum number of integers to sort */

/*
 * minimum_sort:
 *      This function takes in an array of integers and size of the array
 *      and sorts it in place using the minimum_sort algorithm. This 
 *      algorithm has a time complexity of O(n^2) where 'n' is the size 
 *      of the array, which is not very efficient. Therefore, for large 
 *      arrays use a more efficient algorithm such as quicksort.
 *
 *      Arguments:
 *      -- array:  the array to be sorted
 *      -- num_elements: the length of the array to be sorted
 *
 *      Return value: none.
 *
 */

void minimum_sort(int array[], int num_elements)
{
    int start = 0;

    int temp, index;

    while (start < num_elements)
    {
        /* 
         * smallest stores the index of the smallest element 
         * encountered so far in the unsorted part of the array
         */

        int smallest = start;

        for (index = start; index < num_elements; index++)
        {
            if(array[index] < array[smallest])
            {
                smallest = index;
            }
        }
        
        /*
         * Moving the smallest element found to the beginning of 
         * the unsorted part of array you searched
         */

        temp = array[start];
        array[start] = array[smallest];
        array[smallest] = temp;
        
        start++;
    }

    /* Check that the array is sorted correctly. */

    for (index = 1; index < num_elements; index++)
    {
        assert(array[index] >= array[index - 1]);
    }
}

/*
 * bubble_sort:
 *      This function takes in an array of integers and size of the array
 *      and sorts it in place using the bubble_sort algorithm. This 
 *      algorithm has a time complexity of O(n^2) where 'n' is the size 
 *      of the array, which is not very efficient. Therefore, for large 
 *      arrays use a more efficient algorithm such as quicksort.
 *
 *      Arguments:
 *      -- array:  the array to be sorted
 *      -- num_elements: the length of the array to be sorted
 *
 *      Return value: none.
 *
 */

void bubble_sort(int array[], int num_elements)
{
    int x, y;

    /*
     * Iterate through an array, compare each pair of elements and
     * swap the two elements if necessary.
     *
     */

    for (x = 0; x < num_elements; x++)
    {
        for (y = 0; y < num_elements - 1; y++)
        {
            /* 
             * Re arrange the order of the two consecutive elements 
             * if the two elements are out of order
             *
             */
            if (array[y] > array[y + 1])
            {
                int temp = array[y + 1];

                array[y + 1] = array[y];

                array[y] = temp;
            }
        }
    }

    /* Check that the array is sorted correctly. */

    for (x = 1; x < num_elements; x++)
    {
        assert(array[x] >= array[x - 1]);
    }
}

/*
 * cmd_args_error:
 *      This function prints out the error message when called.
 *      
 *      Arguments:
 *          program_name: char pointer, which represents the program name
 *
 *      Return value: none
 *
 */

void cmd_args_error(char* program_name)
{
    fprintf(stderr, 
            "usage: %s [-b] [-q] number1 [number2 ... ] \
            (maximum 32 numbers)\n", 
            program_name);
    exit(1);
}

int main(int argc, char* argv[])
{
    int numbers[MAX_NUMBERS];

    int i;
    int num_ints = 0;
    int quiet = 0;  /* Value for the "-q" optional argument. */

    int bubble_flag = 0; /* Value for the "-b" optional argument */

    /*
     * Print the error message if there are no command line arguments
     * other the the program's name.
     *
     */

    if (argc == 1)
    {
        cmd_args_error(argv[0]);
    }

    for (i = 1; i < argc; i++)  /* Skip argv[0] (program name). */
    {
        /*
         * Use the 'strcmp' function to compare the argv values
         * to a string of your choice (here, it's the optional
         * argument "-q").  When strcmp returns 0, it means that the
         * two strings are identical.
         */

        if (strcmp(argv[i], "-q") == 0)  /* Process optional arguments. */
        {
            quiet = 1;  /* This is used as a boolean value. */
        }

        else if (strcmp(argv[i], "-b") == 0)
        {
             bubble_flag = 1;
        }

        /* Process non-optional arguments here. */
        else
        {
            /* The program will be able to accept up to 32 numbers 
               (integers) on the command line. */

            if (num_ints > 31)
            {
                cmd_args_error(argv[0]);
            }

            numbers[num_ints] = atoi(argv[i]);
            num_ints++;
        }
    }

    /*
     * Print the error message if there are no integer command line arguments,
     * meaning that there are no integers to sort.
     *
     */

    if (num_ints == 0)
    {
        cmd_args_error(argv[0]);
    }

    /*
     * If the -b optional command line argument was used, then use
     * the bubble_sort method. If no -b command line argument was
     * specified, then use the minimum_sort method instead.
     *
     */

    if (bubble_flag)
    {
        bubble_sort(numbers, num_ints);
    }
    else
    {
        minimum_sort(numbers, num_ints);
    }

    /* 
     * If the -q was not in any of the command line arguments, 
     * then print out the resulting sorted array.
     *
     */
 
    if (!quiet)
    {
        for (i = 0; i < num_ints; i++)
        {
            printf("%d\n", numbers[i]);
        }
    }

    return 0;
}
