
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    char ch, file_name[] = "animal_farm_chapter_1.txt";
    FILE *fp;

    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("The contents of %s file are:\n", file_name);

    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);

    fclose(fp);
}