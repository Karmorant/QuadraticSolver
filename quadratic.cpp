#include <stdio.h>
#include "compare.h"
#include "quadratic_functions.h"
#include "input.h"
#include "output.h"

//create 

int main()
{
    quadratic_coeffs coeffs = {};
    read_coeffs(&coeffs);
    
    quadratic_roots   roots = {};
    give_answers(solve_quadratic(&coeffs, &roots), &roots);

    return 0;
}

// Interactive 
// char buf[123123];
// input ---> buf // sscanf strod   
// Errors:
// 1. Buffer overflow
// 2. Invalid input
// ---> msg 

// exit() == ban
// quit --> return

// Unit tests 
// 1. Unit tests через код: 0 0 0 theshold хитрые
// ****2. Unit tests через файл -2.3 2 3

// Doxygen --> ваша
// Readme.md: markdown
