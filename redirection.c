#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include "shell.h"

int redirect(char *input){
    printf("HANDLING REDIRECT!!\n");

    char **redirectees = malloc(1024 * sizeof(char *));
    char cpy[1024];
    strcpy(cpy, input);


    int counter = 0;
	  while(input){
        // if(strstr(input, ">>")){
        //     redirectees[counter] = strsep(&input, ">>");
        // }

        if(strchr(input, '>')){
		    redirectees[counter] = strsep(&input, ">");
        } else {
		    redirectees[counter] = strsep(&input, "<");
        } 
		counter++;
	}

    printf("1 %s\n", redirectees[0]);
    printf("2 %s\n", redirectees[1]);

    // if(strstr(cpy, ">>")){
    //     printf("REDIRECTING NOW>>>>>>>>!!!\n");
    //     int temp_stdout = dup(STDOUT_FILENO);
    //     int file = open(redirectees[1], O_CREAT | O_APPEND | O_WRONLY, 0644);
    //     dup2(file, STDOUT_FILENO);
    //     run_commands(redirectees[0]);
    //     dup2(temp_stdout, STDOUT_FILENO);
    //     close(file);
    //     free(redirectees);

    //     return 0;
    // }

    if(strchr(cpy, '>')){
        printf("REDIRECTING NOW>>>!!!\n");
        int temp_stdout = dup(STDOUT_FILENO);
        int file = open(redirectees[1], O_CREAT | O_WRONLY, 0644);
        dup2(file, STDOUT_FILENO);
        run_commands(redirectees[0]);
        dup2(temp_stdout, STDOUT_FILENO);
        close(file);
        free(redirectees);

        return 0;
    }

    if(strchr(cpy, '<')){
        printf("REDIRECTING NOW<<<!!!\n");
        int temp_stdin = dup(STDIN_FILENO);
        int file = open(redirectees[1], O_RDONLY, 0644);
        if(file < 0){
            printf("File does not exist!\n");
            return 0;
        }
        dup2(file, STDIN_FILENO);
        run_commands(redirectees[0]);
        dup2(temp_stdin, STDIN_FILENO);
        close(file);
        free(redirectees);

        return 0;
    }

    
}
