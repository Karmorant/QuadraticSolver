#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "UI_functions.h"


void clear_buf(char *buf)
{
    for (int i = 0; i < MAXL; i++)
    { 
        buf[i] = '\0';
    }
} 

void show_menu()
{
    printf("\t\t------Menu-----\n"
           "\tTo get command list enter: help\n");
    
}



int write_buf (char *buf)
{
    int c = 0;
    clear_buf(buf);
    for (int i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i >= MAXL - 1)
        {
            printf("OVERFLOW_ERROR. Please try again.\n");
            while ((c = getchar()) != EOF && c != '\n') {};
            return OVERFLOW_ERROR;
        }
        else
        {
            buf[i] = (char) c;
        }
    }
    return 1;
}


int check_command(char *buf)
{

    if (strncmp(buf, quit_f, MAXL) == 0) 
    {
        return OPT_QUIT;
    }
    else if (strncmp(buf, menu_f, MAXL) == 0)
    {
        return OPT_MENU;
    }
    else if (strncmp(buf, help_f, MAXL) == 0)
    {
        return OPT_HELP;
    }
    else if (strncmp(buf, solve_f, MAXL) == 0)
    {
        return OPT_SOLVE;
    }
    else
    {
        return INPUT_ERROR;
    }
}



void show_help ()
{
    printf("\t\t------List of commands-----\n\n");
    printf("\tquit     ----->  Close the program            \n"
           "\tmenu     ----->  Return to the Menu page      \n"
           "\thelp     ----->  Display help informatio      \n"
           "\tsolve    ----->  Solves quadratic equations   \n");

}

