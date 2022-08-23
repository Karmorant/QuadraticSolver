#include <stdio.h>
#include <math.h>
#include <cmath>
#include <assert.h>

double x1 = NAN;
double x2 = NAN;

enum non_trivial_roots
{   
    all_num = -1, no_roots = 0
};

struct quadratic_coeffs
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
};

void read_coeffs(quadratic_coeffs *coeffs)
{
    printf("Enter coefficients of equation\n");
    scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c);
}


int solve_quadratic(quadratic_coeffs *coeffs, double *x1, double *x2) 
{
    if (coeffs->a == 0)
    {
        if (coeffs->b == 0)
        {
            if (coeffs->c == 0)
            {
                return all_num;
            }
            return no_roots;
        }
        *x1 = (-coeffs->c / coeffs->b);
        return 1;
    }
    else
    {
        if (coeffs->b == 0)
        {
            if (coeffs->c == 0)
            {
                *x1 = 0;
                return 1;
            }
            else if (coeffs->c > 0)
            {
                if (coeffs->a > 0)
                {
                    return no_roots;
                }
                else
                { 
                    *x1 =  sqrt(-coeffs->c / coeffs->a);
                    *x2 = -sqrt(-coeffs->c / coeffs->a);
                    return 2;
                }
            }
            else
            { 
                if (coeffs->a > 0)
                {
                        *x1 =  sqrt(-coeffs->c / coeffs->a);
                        *x2 = -sqrt(-coeffs->c / coeffs->a);
                        return 2;
                }
                else
                {
                    return no_roots;
                }
            }    
        }
        else
        {
            if (coeffs->c == 0)
            {
                *x1 = 0;
                *x2 = -coeffs->b /coeffs->a;
                return 2;
            }
            else
            {
                double D = (coeffs->b*coeffs->b) - (4*coeffs->a*coeffs->c);
                if (D > 0)
                {
                    *x1 = (-coeffs->b + sqrt(D)) / (2*coeffs->a);
                    *x2 = (-coeffs->b - sqrt(D)) / (2*coeffs->a);
                    return 2;
                }   
                else if (D == 0)
                {
                    *x1 = -coeffs->b / 2 / coeffs->a;
                    return 1;
                }
                else
                {
                    return no_roots;
                }
            }
        }
    } 
}

int main ()
{
    quadratic_coeffs coeffs = {};
    read_coeffs(&coeffs);
    
    switch (solve_quadratic(&coeffs, &x1, &x2))
    {
        case -1:
            printf("Solution of this equation: all rational numbers")  ;
            break;
        case  0:
            printf("There is no solution for this equation"); 
            break;
        case  1:
            printf("Solution of this equation:\n %lf", x1);
            break;
        case 2:
            printf("Solutions of this equation:\n %lf, %lf", x1, x2);
            break;
        default:
            break;
    }
    
    return 0;
}
