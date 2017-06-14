/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
    
     if(n < 0)
    {
        return false;
    }
    else 
    {
        int f = 0, l = n - 1;
        int mid = (f + l) / 2;
        while(f<=l)
        {
            if(value < values[mid])
                l= mid- 1;
            else if(value== values[mid])
            {
                return true;
            }
            else
                f= mid+ 1;
            mid= (f+l)/ 2;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    int swap=0;
     for (int i = 0 ; i < ( n - 1 ); i++)
        {
        for (int j = 0 ; j < n - i - 1; j++)
          {
            if (values[j] > values[j+1]) /* For decreasing order use < */
            {
                swap       = values[j];
                values[j]   = values[j+1];
                values[j+1] = swap;
            }
          }
        }
 
    
    return;
}
