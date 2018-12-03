#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include "redirection.h"
#include "pipe.h"

char **parse_args(char *input, char **buffer){

    int counter = 0;
	while(input){
		buffer[counter] = strsep(&input, " ");
		counter++;
	}

}

int run_commands(char *input){
    if(strchr(input, '>') || strchr(input, '<')){
        int a = fork();
        if(!a){
            redirect(input);
        }
        int p, status;
        p = wait(&status);
        return 0;
    }

    if(strchr(input, '|')){
        printf("PIPING\n");
        pipes2(input);
        return 0;
    }

    char **parsed_args = malloc(1024 * sizeof(char *));
    parse_args(input, parsed_args);

    if(strcmp(parsed_args[0],"exit") == 0){
		exit(0);
	}

	if(strcmp(parsed_args[0], "cd") == 0){
		if(chdir(parsed_args[1]) == -1){
			printf("Bombshell: cd: %s: No such file or directory\n", parsed_args[1]);
		}
        return 0;
	}

    // printf("%s", input[0]);
    int a = fork();
    if(!a){
        execvp(parsed_args[0], parsed_args);
    }
    else{
    	int p, status;
    	p = wait(&status);
    	free(parsed_args);
    }
    return 0;
}

void run(char *input){
    char **args = malloc(1024 * sizeof(char *));

    int counter = 0;
	while(input){
		args[counter] = strsep(&input, ";");
        printf("running command: %s\n", args[counter]);
		run_commands(args[counter]);
		counter++;
	}

    free(args);
}

static void sighandler(int signo){
	char dir[100];
	getcwd(dir, sizeof(dir));
    printf("\nBombshell: %s $ ", dir);
	fflush(stdout);
}

int main(){

    char *input = malloc(1024 * sizeof(input));

    while(1){
    	signal(SIGINT, sighandler);
        char dir[100];
        getcwd(dir, sizeof(dir));

        printf("Bombshell: %s $ ", dir);
        fflush(stdout);

        fgets(input, 1023, stdin);

        input[strlen(input) - 1] = 0;

        // printf("%s\n", input);
        run(input);

    }

}
