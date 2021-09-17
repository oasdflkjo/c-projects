#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Using bitwise operation instead of modulus to see that if the number is even or odd.

// quote from stackoverflow
// Modern optimizers will convert expressions like (value% 2) != 0 automatically to the above expressions.

bool is_num_odd(uint32_t num)
{
    if ((num & 0x1) > 0)
    {
        return true;
    }
    return false;
}

void print_odd_or_even(uint32_t num)
{
    if (is_num_odd(num))
        printf("odd\n");
    else
        printf("even\n");
}

int main(void)
{
    uint32_t num1 = 5;
    uint32_t num2 = 6;

    print_parity(num1);
    print_parity(num2);

    return 0;
}