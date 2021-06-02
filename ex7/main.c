#include <stdio.h>

// Crucial condition
// *str has to contain '\0' at the end
void reverse(char *str)
{
    // null check
    if (str == 0)
    {
        return;
    }

    // empty check
    if (*str == 0)
    {
        return;
    }

    // create pointers and temp
    char *start, *end, temp;
    start = end = str;

    // put end pointer to end of the string
    do
    {
        end++;
    } while (*end != '\0');
    end--;

    // reverse
    while (start < end)
    {
        temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

void main()
{
    char array[] = "this text is in order";
    int size = 12;
    reverse(array);
    printf("%s\n", array);
}
