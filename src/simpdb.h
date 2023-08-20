#ifndef SIMPDB_H
#define SIMPDB_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum{QUIT_SUCCESS, ERROR_OCCURS, REACHED_EOF} exit_status;

static const int32_t SUCCESS = 0;
static const int32_t ERROR = 1;

#endif