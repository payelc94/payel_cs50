/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: saying the user to enter two or three command line arguments
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // TODO: converting the second argument in command line into an integer using atoi
    int n = atoi(argv[1]);

    /* TODO: If number of arguments in the command line are 3 then convert the
             third argument into long using atoi and generate uniformly distributed pseudo-random numbers using srand48 */
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    /* TODO: multiplying the double-precision floating value(drand48 generates uniformly distributed pseudo-random numbers
            with   the limit defined and converting into int and displaying  it 
             for n times using a for loop */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
