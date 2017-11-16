/*
 * This is an implementation of binary search and bubble sort in C, as part of CS50 homework for week 3.
 * It incorporates comments I received on the binarySearch and bubbleSort functions which I implemented in JS.
 * Namely - the search function assigns values[guess_index] its own variable "guess"...
 * ... and the sort function uses a bool instead of an int for its swap counter.
 *
 *
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <math.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    sort(values, n);
    int max_index = n-1;
    int min_index = 0;
    int guess_index;
    int guess;
    while (max_index != min_index + 1)
    {
        guess_index = floor((max_index+min_index)/2);
        guess = values[guess_index];
        if (value == guess)
        {
            return true;
        }
        else if (guess > value)
        {
            max_index = guess_index;
        }
        else if (guess < value)
        {
            min_index = guess_index;
        }
    }
    return false;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm of O(n^2)
    bool did_swap = true;
    while (did_swap == true)
    {
        did_swap = false;
        for (int i = 0; i < n-1; i++)
        {
            if (values[i] > values[i+1])
            {
                int temp = values[i+1];
                values[i+1] = values[i];
                values[i] = temp;
                did_swap = true;
            }
        }
    }
    return;
}
