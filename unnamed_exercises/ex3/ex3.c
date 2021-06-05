#include<stdio.h>

// find number of occurences 
int occurence(int a[], int item, int c)
{
    int number_of_occurences = 0;
    for (int i = 0; i < c; i++)
    {
        if (a[i]==item)
        {
            number_of_occurences++;
        }
        
    }
    return number_of_occurences;
}

// copy elements in an array to another array
void copy_array(int a[], int b[], int c)
{
    for (int i = 0; i < c; i++)
    {
        b[i]=a[i];
    }
}

// add value to every element in array
void add_to_array(int a[],int value,int c)
{
    for (int i = 0; i < c; i++)
    {
        a[i]=a[i]+value;
    }
}

int main(){

    // 1
    /* int a[]={1,2,3,4,5,66,4,8};
    printf("%d",occurence(a,4,7)); */

    // 2
    /* int a[]={0,1,2,3,4,5};
    int b[10];
    int i;
    copy_array(a,b,6);
    for(i=0;i<6;i++) printf("%d ",*(b+i)); */

    // 3
    int i,a[]={44,11,1,10,100,4,1,10,8,2};
    int c=10;
    add_to_array(a,33,c);
    for(i=0;i<c;i++)
    printf("%d ",a[i]);
}
