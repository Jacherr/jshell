#ifndef __KEYWORD_H
#define __KEYWORD_H

/* Keyword to desribe a string literal. Other keywords inside are NOT escaped. */
#define KW_STRINGLIT '"'
/* Keyword to describe a string literal, in which other keywords are escaped. */
#define KW_STRINGLIT_ESC '\''

/* Keyword to escape other keywords. */
#define KW_ESC '\\'

/* Pipe the output of one command to the input of another. */
#define KW_PIPE '|'

/* Run a command after another if the first command was successful (returned EXIT_SUCCESS). */
#define KW_CHAIN "&&"

/* Separates commands to run one after another regardless of the return result of each. */
#define KW_SEP ';'

#endif /* #ifndef __KEYWORD_H */