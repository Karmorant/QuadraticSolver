/**
 * \brief Main.cpp -    main file of projekt
 *  
 * Performs initialization and control of the interface,
 * using the following commands:
 * 
 * quit     ----->  Close the program            
 * menu     ----->  Return to the Menu page      
 * help     ----->  Display help informatio     
 * solve    ----->  Solves quadratic equations
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "UI_functions.h"
#include "calculation.h"
#include "input.h"
#include "output.h"
#include "compare.h"
#include "UNItest.h"
#include <assert.h>


int main()
{
    char buf[MAXL] = {0};
    quadratic_coeffs coeffs = {};
    quadratic_roots   roots = {};  

    int status = OPT_MENU;

    show_menu();
    while (status != OPT_QUIT)
    {
        clear_buf(buf);
        //the next while loop keeps the program
        //from running until the input exceeds the buffer capacity
        while(write_buf (buf) == OVERFLOW_ERROR) {};
        switch (check_command(buf))
        {
        case INPUT_ERROR:
                printf("Incorrect input. Try again.\n");
                break;
        case OPT_QUIT:
                printf("Termination of work.\n");
                return status = OPT_QUIT; 
                break;
        case OPT_MENU:
                show_menu();
                break;
        case OPT_HELP: 
                show_help();
                break;
        case OPT_SOLVE:
                read_coeffs(&coeffs, buf);
                print_answers(solve_quadratic(&coeffs, &roots), &roots);
                show_menu();
                break;
        default:
                return MATCH_ERROR;
                break;
        }
    }

    return 0;
}

