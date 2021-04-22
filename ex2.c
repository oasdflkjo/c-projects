#include <stdio.h>

// reverse array
void reverse_array(int a[], int c)
{
    int i = 0, temp;
    c -= 1; // arrays start at 0 :^)
    while (i < c)
    {
        temp = a[i];
        a[i] = a[c];
        a[c] = temp;
        i++;
        c--;
    }
}

// return median of array
int median(int given_numbers[], int array_length)
{
    // bublesort
    long c, d, t;
    for (c = 0; c < array_length - 1; c++)
    {
        for (d = 0; d < array_length - c - 1; d++)
        {
            if (given_numbers[d] > given_numbers[d + 1])
            {
                t = given_numbers[d];
                given_numbers[d] = given_numbers[d + 1];
                given_numbers[d + 1] = t;
            }
        }
    }

    // if size is odd return middle else return average of 2 midlest
    if(array_length % 2 == 0){
        int ret = given_numbers[array_length/2] + given_numbers[(array_length/2)+1];
        return ret/2;
    }
    else
        return given_numbers[array_length/2];
}


// multiply elements
void multiply_to_array(int a[],int value,int c){
    for (int i = 0; i < c; i++)
    {
        a[i]=a[i]*value;
    }
};

void main()
{
    int i;

    // 1
    /*a[]={44,11,1,10,100,4,1,10,8,2};
    int c=10;
    reverse_array(a,c);
    for(i=0;i<c;i++)
    printf("%d ",a[i]); */

    // 2
    /* int my_array[] = {66,-100,2,-7,99,123,-44,48,53,4};
    int c = 10;
    median(my_array, c);
    for (i = 0; i < c; i++)
    printf("%d ", my_array[i]);
    
    printf("\n");
    printf("%d", median(my_array, 10));

    printf("\n");
    printf("%d", 5/2);
    */

    // 3
    /* int i,a[]={44,11,1,10,100,4,1,10,8,2};
    int c=10;
    multiply_to_array(a,33,c);
    for(i=0;i<c;i++)
    printf("%d ",a[i]); */
};
