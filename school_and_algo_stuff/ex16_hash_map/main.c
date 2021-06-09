#include <stdio.h>
#include <stdint.h>
#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    uint8_t age;
} person;

person *hash_table[TABLE_SIZE];

uint32_t
hash(char *name)
{
}

int main(void)
{
}