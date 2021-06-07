// demonstration of loopkup table usage
// shifting program resource usage to memory use
// instead of cup cycles

#include <stdio.h>
#include <stdint.h>

uint8_t lookup_table[256] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2,
                             2, 3, 2, 3, 3, 4, 1, 2, 2, 3,
                             2, 3, 3, 4, 2, 3, 3, 4, 3, 4,
                             4, 5, 1, 2, 2, 3, 2, 3, 3, 4,
                             2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
                             3, 4, 3, 4, 4, 5, 3, 4, 4, 5,
                             4, 5, 5, 6, 1, 2, 2, 3, 2, 3,
                             3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
                             2, 3, 3, 4, 3, 4, 4, 5, 3, 4,
                             4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
                             3, 4, 4, 5, 3, 4, 4, 5, 4, 5,
                             5, 6, 3, 4, 4, 5, 4, 5, 5, 6,
                             4, 5, 5, 6, 5, 6, 6, 7, 1, 2,
                             2, 3, 2, 3, 3, 4, 2, 3, 3, 4,
                             3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
                             4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
                             2, 3, 3, 4, 3, 4, 4, 5, 3, 4,
                             4, 5, 4, 5, 5, 6, 3, 4, 4, 5,
                             4, 5, 5, 6, 4, 5, 5, 6, 5, 6,
                             6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
                             3, 4, 4, 5, 4, 5, 5, 6, 3, 4,
                             4, 5, 4, 5, 5, 6, 4, 5, 5, 6,
                             5, 6, 6, 7, 3, 4, 4, 5, 4, 5,
                             5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
                             4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
                             6, 7, 6, 7};

uint8_t count_ones_loop(uint8_t x)
{
    uint8_t result = 0;
    while (x != 0)
    {
        x = x & (x - 1);
        result++;
    }
    return result;
}

uint8_t count_ones_lookup(uint8_t x)
{
    return lookup_table[x];
}

// just a helper function to generate lookup table for this program
void generate_lookup_table()
{
    uint8_t number = 0b00000000;
    for (uint8_t i = 1; i < 255; i++)
    {
        printf("%u,", count_ones_loop(number++));
        if (i % 10 == 0 && i != 0)
            printf("\n");
    }
    printf("\n");
}

int main()
{
    uint8_t number = 0b01000010;
    printf("%u this was loop operation\n", count_ones_loop(number));
    printf("%u this was lookup operation\n", count_ones_lookup(number));
}