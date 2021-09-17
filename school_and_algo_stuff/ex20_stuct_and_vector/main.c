#include "complex.h"

int main(void)
{
    Complex c1 = {1, 2};
    print_complex(c1);
    Complex c2 = {3, 4};
    print_complex(c2);

    Complex *c3 = complex_addition(c1, c2);
    print_complex(*c3);
    free(c3);

    read_complex(&c1);
    print_complex(c1);

    return 0;
}