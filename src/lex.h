#ifndef __LEX_H
#define __LEX_H

#include <unistd.h>

// TODO: move lexing stuff to its own file?

enum lex_entry_type
{
    /* path or program name found in PATH */
    LEX_COMMAND_NAME,
    /* program arguments */
    LEX_COMMAND_ARG,
    /* >>, >, etc */
    LEX_COMMAND_REDIRECT,
    /* ; */
    LEX_COMMAND_SEP,
    /* a command embedded in another, i.e. $(cat x) */
    LEX_COMMAND_SUB
};

struct lex_data_redirect_fd
{
    int fd;
};

/*  an individual token produced from the command line which may have associated 
    data 
*/
struct lex_token
{
    enum lex_entry_type type;
    /*  any additional data based on the type */
    union lex_data {
        /*  LEX_COMMAND_REDIRECT */
        struct lex_data_redirect_fd redirect_fd;
        /*  where the data is just the string format of the arg(s)
            for example a program or path name, or argument or set of arguments 
            joined via "" or ''
            LEX_COMMAND_NAME LEX_COMMAND_ARG 
        */
        char* data_string;
        /*  where there is no data
            LEX_COMMAND_SEP
        */
        char data_none;
    } lex_data;
    struct lex_token* next;
};

/*  Lexical analysis state. This includes a cursor as its primary construct. This
    struct does not contain any stateful information about the execution environment
    such as variables; only what is needed for lexical analysis.
*/
struct lexer
{
    size_t cursor;
};

/*  Yields the next sequence of lexical tokens that may be further parsed.
    In general, this is designed to be as lazy as possible. The lexical analysis 
    will produce a sequence of tokens based on the next block from the input root.
    
    For example, if we have a while loop defined at the root level and a for loop
    within it, the produced sequence of tokens will include both the while loop
    and for loop (because it may affect execution if these are not parsed).
    This means, in general, creating as small blocks as possible will improve
    lexical performance.

    Lexing is paused when a newline is reached, unless the newline is delimited with
    a `\`, or we are inside a block, such as a while loop.
*/
struct lex_token* extract_statement(struct lexer* lexer, char* input);

#endif /* #ifndef __LEX_H */