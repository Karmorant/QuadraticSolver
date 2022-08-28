#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UI_functions.h"
#include "quadratic_functions.h"
#include "input.h"
#include "output.h"
#include "compare.h"
#include "UNItest.h"

char buf[MAXL] = {0};

int main()
{

    quadratic_coeffs coeffs = {};
    quadratic_roots   roots = {};

    

    int status = OPT_MENU;

    show_menu(); 
    while (status != OPT_QUIT)
    {
        clear(buf);
        while(write_buf (buf) == OVERFLOW_ERROR)
                ;
        switch (check_command(buf))
        {
        case INPUT_ERROR:
                printf("Incorrect input. Try again.\n");
                break;
        case OPT_QUIT:
                status = OPT_QUIT;
                printf("Have a nice day.\n");
                break;
        case OPT_MENU:
                show_menu();
                break;
        case OPT_HELP: 
                show_help();
                break;
        case OPT_SOLVE:
                clear(buf);
                read_coeffs(&coeffs, buf);
                give_answers(solve_quadratic(&coeffs, &roots), &roots);
                show_menu();
                break;
        default:
                break;
        }
    }

    return 0;
}

// Unit tests 
// 1. Unit tests через код: 0 0 0 theshold хитрые
// ****2. Unit tests через файл -2.3 2 3

// Doxygen --> ваша
// Readme.md: markdown
