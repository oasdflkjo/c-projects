#include <stdio.h>
#include <stdlib.h>

typedef struct Complex Complex;

struct Complex
{
    float real;
    float im;
};

Complex *complex_addition(Complex a, Complex b);
void read_complex(Complex *number);
void print_complex(Complex number);