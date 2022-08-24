#include <stdio.h>
#include <math.h>
#include <cmath>
#include <assert.h>

double x1 = NAN;
double x2 = NAN;

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

void read_coeffs(quadratic_coeffs *coeffs);

int solve_linear(quadratic_coeffs *coeffs, double *x1);

int solve_quadratic(quadratic_coeffs *coeffs, double *x1, double *x2);

void give_answers (int n_roots);


int main ()
{
    quadratic_coeffs coeffs = {};
    read_coeffs(&coeffs);
    give_answers(solve_quadratic(&coeffs, &x1, &x2));

    
    return 0;
}

void read_coeffs(quadratic_coeffs *coeffs)
{
    printf("Enter coefficients of equation\n");
    scanf("%lf %lf %lf", &coeffs->a, &coeffs->b, &coeffs->c);
}

int solve_linear(quadratic_coeffs *coeffs, double *x1)
{
    if (coeffs->b == 0)
    {
        if (coeffs->c == 0)
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
        if (coeffs->c == 0)
        {
            return INF_ROOTS;
        }
        else
        {
           *x1 = (-coeffs->c / coeffs->b);
            return 1;
        }
    }
}

int solve_quadratic(quadratic_coeffs *coeffs, double *x1, double *x2) 
{
    if (coeffs->a == 0)
    {
         return solve_linear(coeffs, x1);
    }
    else
    {
        if (coeffs->b == 0 && coeffs->c == 0)
        {
            *x1 =  0;
            return 1;
        }
        else
        {
            double discr = (coeffs->b * coeffs->b)
                     - (4 * coeffs->a * coeffs->c);
            if (discr > 0)
            {
                *x1 = (-coeffs->b + sqrt(discr)) / (2*coeffs->a);
                *x2 = (-coeffs->b - sqrt(discr)) / (2*coeffs->a);
                return 2;
            }   
            else if (discr == 0)
            {
                *x1 = -coeffs->b / (2 * coeffs->a);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

void give_answers (int n_roots)
{
    switch (n_roots)
    {
    case INF_ROOTS:
                printf("Solution of this equation: all rational numbers")  ;
                break;
    case  0:
                printf("There is no solution for this equation"); 
                break;
    case  1:
                printf("Solution of this equation:\n %lf", x1);
                break;
    case  2:
                printf("Solutions of this equation:\n %lf, %lf", x1, x2);
                break;
    default:
                break;
    }
}