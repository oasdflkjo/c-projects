// bruteforce method of timing loops
// it't probably not the best method
// but atleast it's relative quick
// way of getting some ballpark numbers

// would it be better to just analyze
// assembly code to evaluate efficiency?

// TODO
// do not use array to store time
// just count the current average in place
// allso writeup on the limitations
// would be nice

#include <stdio.h>
#include <sys/time.h> // works in unix environments

#define NULL ((void *)0)

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char *s, int sSize)
{
    if (sSize == 0)
        return;
    if (s == NULL)
        return;
    char *end = s - 1 + sSize;
    while (s < end)
    {
        if (*s != *end)
            swap(s++, end--);
    }
}

long approxRollingAverage(long avg, long new_sample, int N)
{

    avg -= avg / N;
    avg += new_sample / N;
    return avg;
}

long averageOfArray(long *array, int size)
{
    long temp;
    for (size_t i = 0; i < 5; i++)
    {
        temp = ((i * temp) + *array++) / (i + 1);
    }
    return temp;
}

#define ITERATIONS 10000
void main()
{
    struct timeval start, end;
    char string[] = "hello";
    int string_size = 5;
    long elapsed_times[ITERATIONS];

    for (size_t i = 0; i < ITERATIONS; i++)
    {
        gettimeofday(&start, NULL);
        //      your algo here      //
        for (size_t i = 0; i < 1000; i++)
        {
            reverseString(string, string_size);
        }
        gettimeofday(&end, NULL);
        elapsed_times[i] = (end.tv_usec - start.tv_usec);
    }

    long micro_sec = averageOfArray(elapsed_times, ITERATIONS);
    printf("Elapsed time in %ld microseconds\n", micro_sec);
}