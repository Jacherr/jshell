#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parse.h"
#include "stringparse.h"

struct lex_token* lex_commandline(char* input)
{
    size_t cursor;
    /* linked list */
    struct lex_token* out;

    
}