#ifndef __PARSE_H
#define __PARSE_H 1

#include <limits.h>
#include <stddef.h>

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

// TODO: move pure string manipulation functions to own file?

#define ARGCOUNT_MAX SHRT_MAX

/* removes preceding and trailing whitespace from input in-place */
void trim_commandline(char* input);

/* splits the command line into words. last element is NULL-termination. */
char** split_commandline(char* input);

/* produces a machine-processable list of items from the command line words (which may each be more than one word) */
struct lex_entry_t* lex_commandline(char** split_commandline);

#endif /* ifndef __PARSE_H */