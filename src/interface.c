#include "interface.h"
#include "simpdb.h"
#include <stdint.h>
#include <stdio.h>

static exit_status
print_prompt(FILE *stream)
{
    return fprintf(stream, prompt) >= 0 ? QUIT_SUCCESS : ERROR_OCCURS;
}

static exit_status
process_input(user_input *buf)
{
    if(! strcmp(buf->buf, ".exit"))
        exit(SUCCESS);
    return QUIT_SUCCESS;
}

exit_status
repl(FILE *in, FILE *out, FILE *err)
{
    user_input buffer;
    buffer.buf = NULL;
    exit_status s = QUIT_SUCCESS;

    print_prompt(out);
    fflush(out);
    if(-1 == (buffer.str_len = getline(&buffer.buf, &buffer.buf_len, in)))
        s = buffer.buf[0] == EOF ? REACHED_EOF : ERROR_OCCURS;
    else
    {
        buffer.buf[-- buffer.str_len] = '\0'; // Ignore '\n'
        process_input(&buffer);
    }

    free(buffer.buf);
    return s;
}