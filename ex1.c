#include <stdio.h>
#include <string.h>

// count average of int array

// find index of biggest number in array

// reverse array with 2 passes cos we don't know its length beforehand

int average(int given_numbers[], int array_length)
{
    int temp = 0;
    for (int i = 0; i < array_length; i++)
    {
        temp+=given_numbers[i];
    }
    return temp/array_length;
}

int find_big(int a[], int c)
{
    int temp = 0;
    int indexOfNumber;
    for (int i = 0; i <= c; i++)
    {
        if (temp<a[i]){
            temp=a[i];
            indexOfNumber=(i);
        }

    }
    return indexOfNumber;
}

void reverse_array(char a[])
{
    int sizeOfArray = strlen(a);

    int i;
    int j = sizeOfArray - 1;
    char mem;

    for (i = 0; i < j; i++)
    {
        mem=a[i];
        a[i]=a[j];
        a[j]=mem;
        j--;
    }
    
}

int main(){
/* 
    int my_array[]={4,2,1,5,3};
    printf("%d",average(my_array,5));
 */

/* 
    int a[]={1,2,3,4,5,66,7,8};
    printf("%d",find_big(a,7));
 */
    int i;
    char a[]="Hello";
    reverse_array(a);
    for(i=0;i<5;i++)
    printf("%c ",a[i]);
}
