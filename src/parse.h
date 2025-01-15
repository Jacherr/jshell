#ifndef __PARSE_H
#define __PARSE_H 1

#include <stddef.h>

// TODO: move lexing stuff to its own file?

enum lex_entry_type_t
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

struct lex_entry_t
{
    enum lex_entry_type_t type;
    /* any additional data based on the type */
    union lex_data {
        /* LEX_COMMAND_REDIRECT */
        struct lex_data_redirect_fd redirect_fd;
        /* where the data is just the string format of the arg(s)
           for example a program or path name, or argument or set of arguments joined via "" or ''
           LEX_COMMAND_NAME LEX_COMMAND_ARG 
        */
        char* data_string;
        /* embedded command, i.e. $(cat x)
           LEX_COMMAND_SUB
         */
        struct lex_entry_t* sub_lex;
        /* where there is no data
           LEX_COMMAND_SEP
        */
        char data_none;
    } lex_data;
    struct lex_entry_t* next;
};

/* produces a machine-processable list of items from the command line words (which may each be more than one word) */
struct lex_entry_t* lex_commandline(char** split_commandline);

#endif /* ifndef __PARSE_H */