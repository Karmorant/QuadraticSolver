#ifndef UI_functions
#define UI_functions
#include <stdio.h>
#include <math.h>



static const char quit_f[]  =      "quit";
static const char menu_f[]  =      "menu";
static const char help_f[]  =      "help";
static const char solve_f[] =     "solve";

static const int MAXL = 10;


enum errors
{
    INPUT_ERROR    = -2,
    OVERFLOW_ERROR = -3,
    MATCH_ERROR    = -4,

};

enum operations
{
    OPT_QUIT   = -1,
    OPT_MENU   =  0,
    OPT_HELP   =  1,
    OPT_SOLVE  =  2,
    
};


void clear_buf(char *buf);
void show_menu();
int  write_buf (char *buf);
int  check_command(char *buf);
void show_help();


#endif /* UI_functions */
