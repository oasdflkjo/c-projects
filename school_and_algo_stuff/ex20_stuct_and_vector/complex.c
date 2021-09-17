#include "complex.h"

// helper functions for this module
float read_user_input(void)
{
    float num;
    char buffer[20];
    for (;;)
    {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%f", &num))
            return num;
        else
        {
            printf("Invalid input.\n");
            printf("Enter number: ");
        }
    }
}

// caller has to frees c
Complex *complex_addition(Complex a, Complex b)
{
    Complex *c = malloc(sizeof(Complex));
    c->real = a.real + b.real;
    c->im = a.im + b.im;
    return c;
}

void read_complex(Complex *number)
{
    printf("Enter real part: ");
    number->real = read_user_input();
    printf("Enter imaginary part: ");
    number->im = read_user_input();
}

void print_complex(Complex number)
{
    printf("%lf %lf\n", number.real, number.im);
}
