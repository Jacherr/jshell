#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parse.h"
#include "stringparse.h"

struct lex_token* lex_token_get_idx(struct lex_token* start, unsigned int idx)
{
    int current_idx = 0;
    struct lex_token* current_token = start;

    if(current_token == NULL)
    {
        return NULL;
    }

    while(current_idx < idx)
    {
        /* this errors in visual studio code */
        #ifdef __GCC__
        current_token = current_token->next;
        #endif
        if(current_token == NULL)
        {
            return NULL;
        }

        current_idx++;
    }
}

struct lex_token* extract_statement(struct lexer* lexer, char* input)
{
    /* linked list */
    struct lex_token* out;
    struct lex_token* last = NULL;

    char** words = split_string_by(input, character_is_newline);
    int word_idx = 0;

    /*  We keep track of block depth to know when to finish extracting statements.
        When we finish processing a single statement, we need to check the block
        depth. If it is zero, then return, else, keep processing statements until
        we actually reach zero.
    */
    int block_depth = 0;

    while(words[word_idx] != NULL)
    {
        int cursor = 0;
        char* word = words[word_idx];


    }

    free_split_string(words);
}