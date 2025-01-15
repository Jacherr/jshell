#ifndef __STRINGPARSE_H
#define __STRINGPARSE_H

#include <limits.h>

#define ARGCOUNT_MAX SHRT_MAX

/* returns 1 if character is whitespace, otherwise zero. */
__always_inline char character_is_whitespace(char character);

/* removes preceding and trailing whitespace from input in-place */
void trim_string(char* input);

/* returns a pointer offset, or -1 if the word index is not valid
   this assumes the input is trimmed
 */
ssize_t string_seek_to_word(char* input, int word_idx);

/* Returns NULL if no such word exists at the index 
   this assumes the input is trimmed, and returns a heap allocated string
   */
char* string_read_word(char* input, int word_idx);

/* splits a string into words. last element is NULL-termination. */
char** split_string(char* input);

#endif /* #ifndef __STRINGPARSE_H */