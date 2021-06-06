#include<stdio.h>

// copying array elementes to another array with pointers
void copy_array(int *a, int *b, int c)
{
    for (int i = 0; i < c; i++)
    {
        *(b+i)= *(a+i) ;
    }
}

// multiply elements in array
// ie multiplying vector with scalar
void multiply_to_array(int *a, int value, int c)
{
    for (int i = 0; i < c; i++)
    {
        *(a+i)= *(a+i) * value;
    }
}

// find biggest number in array
int find_big(int *a, int c){
    int temp = 0;
    for (int i = 0; i < c; i++)
    {
        if (*(a+i) > temp)
        temp = *(a+i);
    }
    return temp;
}


// difference between biggest and smallest number in array
int diff_min_max(int *a, int c)
{
    int biggest=*a, smallest=*a;
    for (int i = 1; i < c; i++)
    {
        if (*(a+i) > biggest)
            biggest = *(a+i);
        if  (*(a+i) < smallest)
            biggest = *(a+i);
    }
    // TODO
    // currently only works with if both are positive numbers
    // needt to work with negative
    return biggest - smallest;
}

// TODO
// remove duplicates from array and return new array size
int remove_duplicate_array(int *a, int n)
{
    return n;
}

void main()
{
    // 1
    /* int a[]={0,1,2,3,4,5};
    int b[10];
    int i;
    copy_array(a,b,6);
    for(i=0;i<6;i++) printf("%d ",*(b+i));  */

    // 2 
    /* int i,a[]={44,11,1,10,100,4,1,10,8,2};
    int c=10;
    multiply_to_array(a,33,c);
    for(i=0;i<c;i++)
    printf("%d ",a[i]); */

    // 3
    /* int a[]={1,2,3,4,5,66,7,8};
    printf("%d",find_big(a,7)); */

    // 4
    /* int a[]={1,2,3,4,5,66,7,8};
    printf("%d",diff_min_max(a,7)); */

    // 5
    int z[]={1,1,1,1,1,2,3,4,4,4,4};
    int l=remove_duplicate_array(z,11);
    printf("%d\n",l);

    for(int i=0; i<l; i++)
    printf("%d ",z[i]);

}
