#include <stdio.h>
#include <limits.h>

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);

/* Determine whether an argument is positive. Signed integer represented in two's complement form */
int int_pos(int x);

int main(int argc, char* argv[])
{
    printf("%d\n", tadd_ok(INT_MAX, -INT_MAX));
    printf("%d\n", tadd_ok(-INT_MAX, -INT_MAX));
    
    return 0;
}

/* ================================================================ */

int tadd_ok(int x, int y)
{
    // When both X and Y are positive, but their sum less than 0, we have positive overflow
    if (int_pos(x) && int_pos(y))
    {
        if (!int_pos(x + y))
            return 1;
    }
    // When both X and Y are negative, but their sum more than or equal to 0, we have negative overflow
    else if (!int_pos(x) && !int_pos(y))
    {
        if (int_pos(x + y))
            return 1;
    }

    return 0;
}

int int_pos(int x)
{   
    /*
        In two's complement form, negative numbers have its first bit set to 1
    */
    return (((x & 0x80000000) == 0) ? 1 : 0);
}