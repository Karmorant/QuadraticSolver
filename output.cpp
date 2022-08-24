#include <stdio.h>
#include "quadratic_functions.h"


void give_answers (int n_roots, quadratic_roots *roots)
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
                printf("Solution of this equation:\n %lf", roots->x1);
                break;
    case  2:
                printf("Solutions of this equation:\n %lf, %lf", roots->x1, roots->x2);
                break;
    default:
                break;
    }
}