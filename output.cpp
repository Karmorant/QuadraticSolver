#include <stdio.h>

#include "output.h"



void give_answers (int n_roots, quadratic_roots *roots)
{
    switch (n_roots)
    {
    case INF_ROOTS:
                printf("\tSolution of this equation: all rational numbers\n")  ;
                break;
    case  0:
                printf("\tThere is no solution for this equation\n"); 
                break;
    case  1:
                printf("\tSolution of this equation:\n %lf\n", roots->x1);
                break;
    case  2:
                printf("\tSolutions of this equation:\n %lf, %lf\n", roots->x1, roots->x2);
                break;
    default:
                break;
    }
}