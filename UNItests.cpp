#include <stdio.h>
#include <math.h>
#include <float.h>

#include "quadratic_functions.h"
#include "compare.h"
#include "UNItest.h"

static const UNItests_t Test[] =   
{
    {INF_ROOTS, NAN,        NAN,              { 0,    0,     0    }},
    {1,         0,          NAN,              { 6,    0,     0    }},
    {2,         3,         -2,                { 1,   -1,    -6    }},
    {2,        -2,          3,                {-1,    1,     6    }},
    {2,         1.224745,  -1.224745,         { 6,    0,    -9    }},
    {2,         0,         -1.6e-7,           { 1e10, 1600,  0    }},
    {1,         1,          NAN,              { 0,    7,    -7    }},
    {2,         1.057715,  -1.197208,         { 5.52, 0.77, -6.99 }},
    {0,         NAN,        NAN,              { 1,    10,    10000}},
    {0,         1,          NAN,              { 5,    2,     7    }},
};


int main()
{


    quadratic_coeffs coeffs = {};
    quadratic_roots   roots = {};

    UNItests(&coeffs, &roots); 

    return 0;
}



void UNItests(quadratic_coeffs *coeffs, quadratic_roots *roots)
{   

    int failedTests = 0;
    int numOfTests = sizeof(Test) / sizeof(UNItests_t);
    for (int curTest = 0;  curTest < numOfTests; curTest++) 
    {
        printf("\tTest %d\n", curTest + 1);

        coeffs->a = Test[curTest].uni_coefs[0];
    
        coeffs->b = Test[curTest].uni_coefs[1];
        
        coeffs->c = Test[curTest].uni_coefs[2];


        printf("Tested coefficients: %lf, %lf, %lf\n", coeffs->a, coeffs->b, coeffs->c);
        solve_quadratic(coeffs, roots);

        if (isnan(roots->x1) && isnan(roots->x1))
        {
            if ((Test[curTest].uni_n_roots == INF_ROOTS || Test[curTest].uni_n_roots == 0) && isnan(Test[curTest].x1) && isnan(Test[curTest].x2))
            {
                printf("TEST COMPLETE\n\n");
            }
            else
            {
                printf("TEST FAILED\n\n");
                failedTests++;
            }
        }
        else if (!isnan(roots->x1) && isnan(roots->x2) && Test[curTest].uni_n_roots == 1)
        {
            if (is_equal(Test[curTest].x1, roots->x1))
            {
                printf("TEST COMPLETE\n\n");
            }
            else
            {
                printf("TEST FAILED\n%lf   \n"
                       "Ecpected: %lf    \n\n",
                        roots->x1, Test[curTest].x1);
                failedTests++;
            }
        }
        else if (!isnan(roots->x1) && !isnan(roots->x2) && Test[curTest].uni_n_roots == 2)
        {
            if (is_equal(Test[curTest].x1, roots->x1) && is_equal(Test[curTest].x2, roots->x2))
            {
                printf("TEST COMPLETE\n\n");  
            }
            else
            {
                printf("TEST FAILED\n%lf, %lf   \n"
                       "Expected: %lf, %lf    \n\n",
                        roots->x1, roots->x2, Test[curTest].x1, Test[curTest].x2);
                failedTests++;
            }
        }
        else
        {
            printf("TEST FAILED\n%lf, %lf   \n"
                   "Ecpected: %lf, %lf    \n\n",
                    roots->x1, roots->x2, Test[curTest].x1, Test[curTest].x2);
            failedTests++;
        }
     
        roots->x1 = NAN;
        roots->x2 = NAN;
    }
    printf("Passed tests: %d. Tests failed: %d\n", numOfTests, failedTests);
}