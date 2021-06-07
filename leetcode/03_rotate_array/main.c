// rotate is a bit ambiguous but essentially
// in this context we just shift array in place
// by x amount

// one solution is to rotate array once
// and then rotate 2 "sub arrays" divided
// by the rotating point

// not working on leetcodes validator but as far as i can see this works

#include <stdio.h>

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void reverse(int *array, int start_position, int end_position)
{
    int *start, *end, temp;
    start = end = array;
    start += start_position;
    end += end_position;

    while (start < end)
    {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void rotate(int *array, int arraysize, int rotate_point)
{
    if (rotate_point <= arraysize && rotate_point > 0)
    {
        reverse(array, 0, arraysize);
        reverse(array, 0, rotate_point);
        reverse(array, rotate_point, arraysize);
    }
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 0};
    int array_size = 8;
    rotate(array, 7, 1);
    printArray(array, array_size);
}
