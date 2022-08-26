#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static const char quit_f[] =    "quit";
static const char menu_f[] =    "menu";
static const char help_f[] =    "help";
static const char solve_f[] =  "solve";
static const char cat_f[] =      "cat";

static const int MAXL = 10;
char buf[MAXL] = {0};

enum errors
{
    INPUT_ERROR    = -2,
    OVERFLOW_ERROR = -3,

};

enum operations
{
    OPT_QUIT  = -1,
    OPT_MENU  =  0,
    OPT_HELP  =  1,
    OPT_SOLVE =  2,
    OPT_CAT   =  3
    
};




void clear();
void show_menu();
void write_buf ();
int  compare(const char *str1, const char *str2, const int size);
int  check_command(char *buf);
void show_help();


int main()
{
    int status = OPT_MENU;
    show_menu(); // tolower
    while (status != OPT_QUIT)
    {
        clear();
        write_buf();
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
                //solve(); //create solve
                break;
        case OPT_CAT:
                //cat();  //creat cat
                break;
        default:
                break;
        }
}


    return 0;
}

void clear()
{
    for (int i = 0; i <= MAXL - 1; i++)
    {
        buf[i] == '\0';
    }
} 

void show_menu()
{
    printf("\t\t------Menu-----\n"
           "\nTo get command list enter: help\n");
    
}

void write_buf ()
{
    char c;
    for (int i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        if (i >= MAXL)
        {
            printf("OVERFLOW_ERROR. Please try again.\n");
            write_buf();
        }
        else
        {
        buf[i] = c;
        }
    }
}

int compare(const char str1[], const char str2[], const int size)
{
    if (strncmp(str1, str2, size) == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int check_command(char buf[])
{
    if (compare(buf, quit_f, MAXL))
    {
        return OPT_QUIT;
    }
    else if (compare(buf, menu_f, MAXL))
    {
        return OPT_MENU;
    }
    else if (compare(buf, help_f, MAXL))
    {
        return OPT_HELP;
    }
    else if (compare(buf, solve_f, MAXL))
    {
        return OPT_SOLVE;
    }
    else if (compare(buf, cat_f, MAXL))
    {
        return OPT_CAT;
    }
    else
    {
        return INPUT_ERROR;
    }
}



void show_help ()
{
    printf("\t\t------List of commands-----\n\n");
    printf("\tquit   ----->  Close the program            \n"
           "\tmenu   ----->  Return to the Menu page      \n"
           "\thelp   ----->  Display help informatio      \n"
           "\tsolve  ----->  Solves all your problems     \n"
           "\tcat    ----->  MEOW                         \n");

}


