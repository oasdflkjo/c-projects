// delete duplicates from unsorted array

// things to consider
// would it be faster to sort the array first and then remove duplicates?


#include<stdio.h>

// removes duplicates and how many variables are in array
int remove_duplicates(int array[], int size_of_a){

    int ret = 0;
    for (int i = 0; i < size_of_a; i++)
    {
       for (int j = i+1; j < size_of_a; j++)
       {
           if(array[i]==array[j]);
           ret++;
       }
  
    }
    return ret;
}

void main(){

    int array[] = {10, 20, 10, 1, 100, 10, 2, 1, 5, 10};
    int array_size = 10;

    for (int i = 0; i < array_size; i++)
    {
       printf("%d ",array[i]);
    }
    printf("\n");

    remove_duplicates(array);

    for (int i = 0; i < array_size; i++)
    {
       printf("%d ",array[i]);
    }
}
