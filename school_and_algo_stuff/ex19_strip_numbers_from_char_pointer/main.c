#include <stdio.h>

int strip_numbers(char *s)
{
    if (s == 0)
    {
        return -1;
    }
    else if (*s == '\0')
    {
        return 0;
    }
    else
    {
        int i = 0;
        char *p = s;
        while (*p != '\0')
        {
            if (*p >= 48 && *p <= 57)
            {
                p++;
            }
            else
            {
                *s = *p;
                p++;
                s++;
                i++;
            }
        }
        *s = '\0';
        return i;
    }
}

int main(void)
{
    char s[] = "asdf5uu1";
    strip_numbers(s);
    printf("%s\n", s);
}