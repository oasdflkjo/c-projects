// testing how to interact os with running commands from c program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *p;
    char ch;
    u_int32_t counter = 0;
    char buffer[500] = "";
    char *filenames[50];
    p = popen("ls", "r");
    if (p == NULL)
    {
        puts("Unable to open process");
        return (1);
    }
    while ((ch = fgetc(p)) != EOF)
    {
        if (ch == '\n')
        {
            counter++;
        }
        putchar(ch);
    }
    pclose(p);
    printf("%u files in this folder\n", counter);
    printf("why not try to script in c? :))\n");

    p = popen("ls", "r");
    if (p == NULL)
    {
        puts("Unable to open process");
        return (1);
    }

    while ((ch = fgetc(p)) != EOF)
    {
        strncat(buffer, &ch, 1);
    }

    printf("%s", buffer);
    return (0);
}
