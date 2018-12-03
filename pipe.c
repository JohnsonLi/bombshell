#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include "shell.h"

#define PIPE_READ 0
#define PIPE_WRITE 1

int pipes(char *input){
    printf("GONNA PIPE\n");

    char **pipees = malloc(1024 * sizeof(char *));

    int counter = 0;
    while(input){
      pipees[counter] = strsep(&input, "|");
      counter++;
  }

    // printf("%s\n", pipees[0]);
    // printf("%s\n", pipees[1]);

    // int temp_stdout = dup(STDOUT_FILENO);

  int p[2];
  pipe(p);
  int a = fork();
  if(a == 0){
    int temp_stdout = dup(STDOUT_FILENO);
    close(p[PIPE_READ]);
    dup2(p[PIPE_WRITE], STDOUT_FILENO);
        // close(p[PIPE_WRITE]);

    char **args_parsed = malloc(1024 * sizeof(char *));
    parse_args(pipees[0], args_parsed);
    execvp(args_parsed[0], args_parsed);

    dup2(temp_stdout, STDOUT_FILENO);

    return 0;
} else {
    int b = fork();
    if(b == 0){
        int temp_stdin = dup(STDIN_FILENO);
        close(p[PIPE_WRITE]);
        dup2(p[PIPE_READ], STDIN_FILENO);
            // close(p[PIPE_READ]);

        char **args_parsed = malloc(1024 * sizeof(char *));
        parse_args(pipees[1], args_parsed);
        printf("running %s\n", args_parsed[0]);
        execvp(args_parsed[0], args_parsed);

        dup2(temp_stdin, STDIN_FILENO);

        return 0;
    }
}

int s, b;
int c, d;
s = wait(&b);
c = wait(&d);

fflush(stdout);

free(pipees);

}

void pipes2(char *input){
    char* pipee = strchr(input,'|');
    char* first = input;
    pipee[0] = 0;
    char* second = pipee + 1;
    char** first_parsed = malloc(1024 * sizeof(char*));
    char** second_parsed = malloc(1024 * sizeof(char*));
    parse_args(first,first_parsed);
    parse_args(second,second_parsed);
    int p[2];
    int pid0 = fork();
    pipe(p);
    if (!pid0){
        int pid = fork();
        if (!pid) {
        // int pid2 = fork();
        // if (!pid2){
            dup2(p[1], PIPE_WRITE);
            close(p[0]);
            execvp(first_parsed[0], first_parsed);
        // }
        }
        else {
        // int pid2 = fork();
        // if (!pid2){
            wait(NULL);
            dup2(p[0], PIPE_READ);
            close(p[1]);
            execvp(second_parsed[0], second_parsed);
        // }
        }
    }
    else{
        wait(NULL);
    }
}
