#ifndef INTERFACE_H
#define INTERFACE_H

#include "simpdb.h"
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char        *buf;
    int16_t     buf_len;
    int16_t     str_len;
} user_input;

typedef enum{QUIT} command;

static const char prompt[] = "simpdb$ ";
static const char input_failed[] = "Unable to read from stdin.";
static const char exit_cmd[] = ".exit";

static exit_status print_prompt(FILE *stream);
static exit_status process_input(user_input *buf);
exit_status repl(FILE *in, FILE *out, FILE *err);

#endif