#ifndef CALCULATION
#define CALCULATION
#include <stdio.h>
#include <math.h>


enum non_trivial_roots
{   
    INF_ROOTS  = -1
};

struct quadratic_coeffs
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

struct quadratic_roots
{
    double x1 = NAN;
    double x2 = NAN;
};



int solve_linear(quadratic_coeffs *coeffs, quadratic_roots *roots);
int solve_quadratic(quadratic_coeffs *coeffs, quadratic_roots *roots);

#endif /* CALCULATION */