#ifndef __STRINGPARSE_H
#define __STRINGPARSE_H

#include <limits.h>

#define ARGCOUNT_MAX SHRT_MAX

/* returns 1 if input starts with starts_with character, 0 otherwise. */
char string_starts_with_char(char* input, char starts_with);

/* returns 1 if input starts with starts_with string (excluding null), 0 otherwise. */
char string_starts_with(char* input, char* starts_with);

/* returns 1 if input ends with ends_with character, 0 otherwise. */
char string_ends_with_char(char* input, char ends_with);

/* returns 1 if input ends with ends_with string (excluding null), 0 otherwise. */
char string_ends_with(char* input, char* ends_with);

/* returns 1 if character is whitespace, otherwise zero. */
char character_is_whitespace(char character);

char character_is_newline(char character);

/* removes preceding and trailing whitespace from input in-place */
void trim_string(char* input);

/* returns a pointer offset, or -1 if the word index is not valid
   this assumes the input is trimmed
 */
ssize_t string_seek_to_next(char* input, int next_idx, char (split_criteria)(char));

/* Returns NULL if no such word exists at the index 
   this assumes the input is trimmed, and returns a heap allocated string
   */
char* string_read_next(char* input, int next_idx, char (split_criteria)(char));

/* splits a string into words. last element is NULL-termination. */
char** split_string_by(char* input, char (split_criteria)(char));

/* frees all elements of a split string and the array itself */
void free_split_string(char** split);

#endif /* #ifndef __STRINGPARSE_H */