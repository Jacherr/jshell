#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parse.h"
#include "stringparse.h"

struct lex_token* extract_statement(struct lexer* lexer, char* input)
{
    /* linked list */
    struct lex_token* out;
    

}