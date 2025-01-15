#include <stdio.h>

#include "help.h"

void print_help()
{
    puts("jshell: jshell [ -e ]");
    puts("jshell: run commands, pipe them, chain them, redirect them");
    puts("jshell: run with no arguments to open a new shell session or refer below for command-line options");
    puts("jshell: -e: evaluate command-line arguments as input");
    puts("jshell: WIP ver 0.0.01-rc0-alpha");
}