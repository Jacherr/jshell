#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "parse.h"

/* returns 1 if character is whitespace, otherwise zero. */
static __always_inline char _character_is_whitespace(char character)
{
    return character == ' ' || character == '\n';
}

void trim_commandline(char* input)
{
    size_t substr_end = strlen(input) - 1, substr_start = 0;
    while(_character_is_whitespace(input[substr_start]))
    {
        substr_start++;
    }

    while(_character_is_whitespace(input[substr_end]))
    {
        substr_end--;
    }

    input[substr_end + 1] = '\0';
    memmove(input, input+substr_start, substr_end+1);
}

/* returns a pointer offset, or -1 if the word index is not valid
   this assumes the input is trimmed
 */
static ssize_t _commandline_seek_to_word(char* input, int word_idx)
{
    size_t cursor = 0;
    char reading_whitespace = 0;
    long current_word_idx = 0;

    for(; cursor < strlen(input); cursor++)
    {
        if(!reading_whitespace && _character_is_whitespace(input[cursor]))
        {
            /* look ahead at end of this word to see its length */
            reading_whitespace = 1;
            current_word_idx++;
        } else if(!_character_is_whitespace(input[cursor]))
        {
            reading_whitespace = 0;
            if(current_word_idx == word_idx)
            {
                return cursor;
            }
        }
    }

    return -1;
}

/* Returns NULL if no such word exists at the index 
   this assumes the input is trimmed, and returns a heap allocated string
   */
static char* _commandline_read_word(char* input, int word_idx)
{
    ssize_t cursor = 0, old_cursor = 0;
    char* out;
    long word_len = 0;

    cursor = _commandline_seek_to_word(input, word_idx);
    if(cursor < 0)
    {
        return NULL;
    }
    old_cursor = cursor;

    // we need to get the length of this word, and then copy it after
    while(input[cursor] != '\0' && !_character_is_whitespace(input[cursor]))
    {
        word_len++;
        cursor++;
    }

    // sanity check
    assert(word_len > 0);

    cursor = old_cursor;
    // +1 for null
    out = malloc(word_len + 1);
    memcpy(out, input + old_cursor, word_len);
    out[word_len] = '\0';

    return out;
}

char** split_commandline(char* input)
{
    int words = 0, current_word_idx = 0;
    // if we are reading
    char reading = 1;
    // should be loads of space
    char** out = malloc(ARGCOUNT_MAX);
    char* current_word;

    trim_commandline(input);
    while(reading)
    {
        if(current_word_idx >= ARGCOUNT_MAX)
        {
            // TODO: ???
            // just cut off extra args for now
            break;
        }

        current_word = _commandline_read_word(input, current_word_idx);
        if(current_word != NULL)
        {
            words++;
            out[current_word_idx] = current_word;
            current_word_idx++;
        } else {
            // done
            reading = 0;
        }
    }

    out[current_word_idx] = NULL;

    return out;
}

struct lex_entry_t* lex_commandline(char** split_commandline)
{
    size_t cursor;
    /* linked list */
    struct lex_entry_t* out;
}