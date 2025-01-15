#include <limits.h>

// TODO: move pure string manipulation functions to own file?

#define ARGCOUNT_MAX SHRT_MAX

/* removes preceding and trailing whitespace from input in-place */
void trim_commandline(char* input);

/* splits the command line into words. last element is NULL-termination. */
char** split_commandline(char* input);