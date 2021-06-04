// function that prints modified string
// shift alphabetically and cycle from z->a and Z->A
// ignore non alphabet characters

// TODO without string.h and with write instead of printf

//#include <unistd.h>
#include <stdio.h>
#include <string.h>

int rotone_main(int argc, char **argv)
{
    if (argc == 1)
    {
        char *string = argv[0];
        int length = strlen(string);

        char temp, *temp_string;
        while (*string != '\0')
        {
            // not shure why i can't manipulate *string ???
            temp = *string;
            // manipulate char according to specs
            // and print it
            if (temp >= 'A' && temp <= 'Z')
            {
                if (temp == 'Z')
                    temp = 'A';
                else
                    temp = temp + 1;
            }
            if (temp >= 'a' && temp <= 'z')
            {
                if (temp == 'z')
                    temp = 'a';
                else
                    temp = temp + 1;
            }
            printf("%c", temp);
            string++;
        }
        printf("\n");
    }
    else
        printf("\n");
}

int main(void)
{
    char *arg0[] = {"abc"};
    rotone_main(1, arg0);
    char *arg1[] = {"Life is better by the campfire."};
    rotone_main(1, arg1);
    char *arg2[] = {"AkjhZ zLKIJz , 23y "};
    rotone_main(1, arg2);
    char *arg3[] = {"a", "b"};
    rotone_main(2, arg3);
}