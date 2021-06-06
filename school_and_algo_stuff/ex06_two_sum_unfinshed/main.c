#include <stdio.h>
#include <stdlib.h>

// helper
int printArray(int array[], int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// brute force approach
int *twoSum_brute(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *returnValues = malloc((*returnSize) * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnValues[0] = i;
                returnValues[1] = j;
                break;
            }
        }
    }

    return returnValues;
}

void main()
{
    int array[] = {2, 7, 11, 15};
    int length = 4;
    int answer_array[] = {0, 0};
    int target = 9;
    twoSum_brute(array, length, target, answer_array);
    printArray(answer_array, 2);
}
