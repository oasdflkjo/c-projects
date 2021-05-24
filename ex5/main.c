#include <stdio.h>

int removeDuplicates(int nums[], int numsSize)
{
    if (numsSize == 0)
    {
        return 0;
    }

    if (numsSize == 1)
    {
        return 1;
    }

    int mem = nums[0];
    int j = 1;
    for (size_t i = 1; i < numsSize; i++)
    {
        if (mem != nums[i])
            mem = nums[j++] = nums[i];
    }
    return j;
}

int printArray(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void main()
{
    int array[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int length = 10;
    int newLength = removeDuplicates(array, 10);
    printArray(array, newLength);
}
