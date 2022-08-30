#include <stdio.h>
#include <math.h>

#include "compare.h"


int is_equal(const double a, const double d, const double epsilon)
{  
    return fabs(a - d) <= epsilon;
} 

int is_greater(const double a, const double d, const double epsilon)
{  
    if (is_equal(a, d, epsilon))
    {
        return false;
    }
    else
    {
        return a > d;
    }
}