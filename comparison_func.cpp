#include <stdio.h>
#include <math.h>

#include "compare.h"


int is_equal(const double a, const double d, const double threshold)
{  
    return fabs(a - d) <= threshold;
} 

int is_greater(const double a, const double d, const double threshold)
{  
    if (is_equal(a, d, threshold))
    {
        return false;
    }
    else
    {
        return a > d;
    }
}