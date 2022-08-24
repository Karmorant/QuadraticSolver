#include <stdio.h>
#include "compare.h"
#include "quadratic_functions.h"
#include "input.h"
#include "output.h"



int main()
{

    quadratic_roots   roots = {};
    quadratic_coeffs coeffs = {};
    read_coeffs(&coeffs);
    give_answers(solve_quadratic(&coeffs, &roots), &roots);

    return 0;
}