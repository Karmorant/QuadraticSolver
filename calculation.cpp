#include <stdio.h>
#include <math.h>

#include "compare.h"
#include "quadratic_functions.h"


int solve_linear(quadratic_coeffs *coeffs, quadratic_roots *roots)
{
    if (is_equal(coeffs->b, 0))
    {
        if (is_equal(coeffs->c, 0))
        {
            return INF_ROOTS;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (is_equal(coeffs->c, 0))
        {
            return INF_ROOTS;
        }
        else
        {
            roots->x1 = (-coeffs->c / coeffs->b);
            roots->x2 = NAN;
            return 1;
        }
    }
}

int solve_quadratic(quadratic_coeffs *coeffs, quadratic_roots *roots) 
{
    if (is_equal(coeffs->a, 0))
    {
         return solve_linear(coeffs, roots);
    }
    else
    {
        if (    is_equal(coeffs->b, 0)
             && is_equal(coeffs->c, 0))
        {
            roots->x1 =  0;
            return 1;
        }
        else
        {
            double discr = (coeffs->b * coeffs->b)
                     - (4 * coeffs->a * coeffs->c);
            double sqrtd = sqrt(discr);
            if (is_greater(discr, 0))
            {
                roots->x1 = (-coeffs->b + sqrtd) / (2 * coeffs->a);
                roots->x2 = (-coeffs->b - sqrtd) / (2 * coeffs->a);
                return 2;
            }   
            else if (is_equal(discr, 0))
            {
                roots->x1 = -coeffs->b / (2 * coeffs->a);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}
