#include <stdio.h>
#define NULL ((void *)0)

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char *s, int sSize)
{
    if (sSize == 0 || sSize == 1)
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

void main()
{
    char string[] = "hello";
    int string_size = 5;
    reverseString(string, string_size);
    printf("%s\n", string);
}