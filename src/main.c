#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "help.h"
#include "parse.h"

int main(int argc, char* argv[])
{
    char test[] = "   test  123 test   ";

    char** out = split_commandline(test);
    int idx = 0;

    while(out[idx] != NULL)
    {
        printf("'%s'\n", out[idx]);
        idx++;
    }


    // if(argc <= 1)
    // {
    //     print_help();
    //     return 0;
    // }

    // while(1)
    // {
    //     /* maximum length of command-line input */
    //     long cli_maxlen = sysconf(_SC_ARG_MAX);
    //     char* commandline = malloc((size_t)cli_maxlen);
    //     fgets(commandline, cli_maxlen, stdin);

    //     int pid = fork();
    //     if(pid < 0)
    //     {
    //         perror("failed to fork");
    //         return EXIT_FAILURE;
    //     } else if(pid == 0)
    //     {
    //         /* child */
    //         puts("im the forked child");
    //         char* argv[] = { "/usr/bin/echo", "im the echo child", NULL };
    //         execvp("echo", argv);
    //     } else {
    //         int stat_loc;
    //         waitpid(pid, &stat_loc, 0);
    //         /* parent */
    //         puts("im the parent after waiting");
    //     }
    // }

    return EXIT_SUCCESS;
}