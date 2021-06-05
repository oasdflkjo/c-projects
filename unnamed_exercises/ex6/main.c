#include <stdio.h>

int printArray(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    // iterate all combinations
    // stop when find solution
    // brute here
    for (size_t i = 0; i < numsSize; i++)
    {
        for (size_t j = 0; j < numsSize; j++)
        {
            if (i == j)
                j++;
            if (i + j == target)
            {
                returnSize[0] == i;
                returnSize[1] == j;
                return returnSize;
            }
        }
    }

    return returnSize;
}

void main()
{
    int retArray[] = {0, 0};
    int array[] = {2, 7, 11, 15};
    int length = 4;
    int target = 9;
    twoSum(array, length, target, retArray);
    printArray(retArray, 2);
}
