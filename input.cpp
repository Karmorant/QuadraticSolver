#include <stdio.h>
#include "quadratic_functions.h"

void read_coeffs(quadratic_coeffs *coeffs)
{
    printf("Enter coefficients of equation\n");
    scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c);
}