#include <stdio.h>
#include <stdlib.h>

float minf(float, float);
u_int32_t mini(u_int32_t, u_int32_t);

// TODO why visual stuodio code scrambles this define to be unreadable
#define min(a, b) _Generic((a), float              \
                           : minf(a, b), u_int32_t \
                           : mini(a, b))

float minf(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}

u_int32_t mini(u_int32_t a, u_int32_t b)
{
    if (a > b)
        return a;
    else
        return b;
}

__INT_FAST8_TYPE__ main()
{
    float a, b;
    a = 0.1, b = 0.2;
    printf("%.1f\n", min(a, b));

    u_int32_t c, d;
    c = 1, d = 2;
    printf("%u\n", min(c, d));
}
