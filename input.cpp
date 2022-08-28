#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "UI_functions.h"
#include "input.h"




void read_coeffs (quadratic_coeffs *coeffs, char *buf)
{
    static double check = NAN;
    printf("\tEnter coefficients of equation\n");
    
    while(write_buf (buf) == OVERFLOW_ERROR)
        ;
    if((sscanf(buf,"%lf %lf %lf %lf\n", &coeffs->a, &coeffs->b, &coeffs->c, &check)) != 3)
    {
        printf("\tInvailed input. Numbers were expected. "
               "Or not all coefficients are entered.\n");
        read_coeffs(coeffs, buf);
    }
    clear(buf);
}
