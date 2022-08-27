#include <stdio.h>
#include <math.h>
#include <float.h>

#include "quadratic_functions.h"
#include "compare.h"
#include "UNItest.h"

static const UNItests_t Test[] =
{
    {INF_ROOTS, NAN, NAN,              {0, 0, 0}},
    {1, 0, NAN,                        {6, 0, 0}},
    {2, 3, -2,                       {1, -1, -6}},
    {2, -2, 3,                        {-1, 1, 6}},
    {2, 1.224745, -1.224745,          {6, 0, -9}},
    {2, 0, -1.6e-7,              {1e10, 1600, 0}},
    {1, 1, NAN,                       {0, 7, -7}},
    {2, 1.057715, -1.197208, {5.52, 0.77, -6.99}},
    {0, NAN, NAN,                 {1, 10, 10000}},
    {0, NAN, NAN,                      {5, 2, 7}},
};



void UNItests(quadratic_coeffs *coeffs, quadratic_roots *roots)
{   int j = 0, k = 0;
    for (int i = 0; i < 10; i++)
    {
        coeffs->a = Test[i].uni_coefs[0];
        coeffs->b = Test[i].uni_coefs[1];
        coeffs->c = Test[i].uni_coefs[2];
        printf("Tested coefficients: %lf, %lf, %lf\n", coeffs->a, coeffs->b, coeffs->c);
        if((solve_quadratic(coeffs, roots)) == Test[i].uni_n_roots)
        {
            if (isnan(roots->x1) && isnan(roots->x1))
            {
                if (Test[i].uni_n_roots == INF_ROOTS || Test[i].uni_n_roots == 0)
                {
                    printf("TEST COMPLET\n\n");
                    j++;
                }
                else
                {
                    printf("TEST FAILED\n\n");
                    k++;
                }
            }
            else if (!isnan(roots->x1) && isnan(roots->x2) && Test[i].uni_n_roots == 1)
            {
                if (Test[i].x1 == roots->x1)
                {
                    printf("TEST COMPLET\n\n");
                    j++;
                }
                else
                {
                    printf("TEST FAILED\n%lf   \n"
                           "Ecpected: %lf    \n\n",
                           roots->x1, Test[i].x1);
                    k++;
                }
            }
            else if (!isnan(roots->x1) && !isnan(roots->x2) && Test[i].uni_n_roots == 2)
            {
                if (Test[i].x1 == roots->x1 && Test[i].x2 == roots->x2)
                {
                    printf("TEST COMPLET\n");
                    j++;  
                }
                else
                {
                    printf("TEST FAILED\n%lf, %lf   \n"
                           "Ecpected: %lf, %lf    \n\n",
                           roots->x1, roots->x2, Test[i].x1, Test[i].x2);
                    k++;
                }
            }
            else
            {
                printf("TEST FAILED\n%lf, %lf   \n"
                       "Ecpected: %lf, %lf    \n\n",
                       roots->x1, roots->x2, Test[i].x1, Test[i].x2);
                k++;
            }
        }
        else
        {
            printf("TEST FAILED\n\n");
            k++;
        }

    }
    printf("Tests completed: %d. Tests failed: %d\n", j, k);
}