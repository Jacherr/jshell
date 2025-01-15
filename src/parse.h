#ifndef __PARSE_H
#define __PARSE_H 1

#include <stddef.h>

// TODO: move lexing stuff to its own file?

enum lex_entry_type_t
{
    LE_COMMAND_NAME,
    LE_COMMAND_ARG,
    LE_COMMAND_SEP
};

struct lex_entry_t
{
    /* raw string of this entry (if any) */
    char* str;
    enum lex_entry_type_t type;
    union {

    } data;
    struct lex_entry_t* next;
};

enum commandline_action_type_t
{
    CLA_RUNCOMMAND,
    CLA_REDIRECT,
    CLA_PIPE
};

struct commandline_action_chain
{
    enum commandline_action_type_t type;
    
};

/* produces a machine-processable list of items from the command line words (which may each be more than one word) */
struct lex_entry_t* lex_commandline(char** split_commandline);

#endif /* ifndef __PARSE_H */