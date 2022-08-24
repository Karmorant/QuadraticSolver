#include <stdio.h>
#include <math.h>


int is_equal   (double a, double b, const double threshold)
{  
    return fabs(a - b) <= threshold;
} 

int is_greater (double a, double b, const double threshold)
{  
    if (is_equal(a, b, threshold))
    {
        return false;
    }
    else
    {
        return a > b;
    }
} 