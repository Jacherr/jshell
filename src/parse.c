#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parse.h"

struct lex_entry_t* lex_commandline(char** split_commandline)
{
    size_t cursor;
    /* linked list */
    struct lex_entry_t* out;
}