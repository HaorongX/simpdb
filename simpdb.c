#include "simpdb.h"
#include "interface.h"

/*
"our main function will have an infinite loop that prints the prompt, gets a line of input, then processes that line of input"
*/

int main()
{
    exit_status e;
    do
    {
        e = repl(stdin, stdout, stderr);
    }while(e == QUIT_SUCCESS);
    return SUCCESS;
}