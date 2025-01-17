#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#include "stringparse.h"

char string_starts_with_char(char* input, char starts_with)
{
    return input[0] == starts_with;
}

char string_starts_with(char* input, char* starts_with)
{
    return strncmp(input, starts_with, strlen(starts_with)) == 0;
}

char string_ends_with_char(char* input, char ends_with)
{
    int len = strlen(input);
    return input[len - 1] == ends_with;
}

char string_ends_with(char* input, char* ends_with)
{
    int input_len = strlen(input), search_len = strlen(ends_with);
    int input_offset = input_len - search_len;
    return strncmp(input + input_offset, ends_with, search_len) == 0;
}

char character_is_whitespace(char character)
{
    return character == ' ' || character == '\n';
}

char character_is_newline(char character)
{
    return character == '\n';
}

void trim_string(char* input)
{
    size_t substr_end = strlen(input) - 1, substr_start = 0;
    while(character_is_whitespace(input[substr_start]))
    {
        substr_start++;
    }

    while(character_is_whitespace(input[substr_end]))
    {
        substr_end--;
    }

    input[substr_end + 1] = '\0';
    memmove(input, input+substr_start, substr_end+1);
}

ssize_t string_seek_to_next(char* input, int next_idx, char (split_criteria)(char))
{
    size_t cursor = 0;
    char reading_whitespace = 0;
    long current_word_idx = 0;

    for(; cursor < strlen(input); cursor++)
    {
        if(!reading_whitespace && split_criteria(input[cursor]))
        {
            /* look ahead at end of this word to see its length */
            reading_whitespace = 1;
            current_word_idx++;
        } else if(!split_criteria(input[cursor]))
        {
            reading_whitespace = 0;
            if(current_word_idx == next_idx)
            {
                return cursor;
            }
        }
    }

    return -1;
}

char* string_read_next(char* input, int next_idx, char (split_criteria)(char))
{
    ssize_t cursor = 0, old_cursor = 0;
    char* out;
    long word_len = 0;

    cursor = string_seek_to_next(input, next_idx, split_criteria);
    if(cursor < 0)
    {
        return NULL;
    }
    old_cursor = cursor;

    // we need to get the length of this word, and then copy it after
    while(input[cursor] != '\0' && !split_criteria(input[cursor]))
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

char** split_string_by(char* input, char (split_criteria)(char))
{
    int words = 0, current_word_idx = 0;
    // if we are reading
    char reading = 1;
    // should be loads of space
    char** out = malloc(ARGCOUNT_MAX);
    char* current_word;

    trim_string(input);
    while(reading)
    {
        if(current_word_idx >= ARGCOUNT_MAX)
        {
            // TODO: ???
            // just cut off extra args for now
            break;
        }

        current_word = string_read_next(input, current_word_idx, split_criteria);
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

void free_split_string(char** split)
{
    int idx = 0;
    while(split[idx] != NULL)
    {
        free(split[idx]);
    }

    free(split);
}