#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include "pipe.h"

char **parse_args(char *input){
	char **args = malloc(1024 * sizeof(char *));

	int counter = 0;
	while(input){
		args[counter] = strsep(&input, " ");
		counter++;
	}

	return args;
}

int run_commands(char ** args_parsed){
	if(strcmp(args_parsed[0],"exit") == 0){
		exit(0);
	}

	if(strcmp(args_parsed[0], "cd") == 0){
		if(chdir(args_parsed[1]) == -1){
			printf("Bombshell: cd: %s: No such file or directory\n", args_parsed[1]);
		}
	} else {

		// char **second = malloc(1024 * sizeof(char *));

		// int i;
		// int j;
		// int pipe_index = 0;
		// int size = sizeof(args_parsed);
		// for(i = 0; i < size; i++){
		// 	printf("%s\n", args_parsed[i]);
		// 	if(strchr(args_parsed[i], '|')){
		// 		pipe_index = i;
		// 		args_parsed[i] = NULL;
		// 		for(j = i + 1; j < size; j++){
		// 			args_parsed[j] = second[j-i-1];
		// 		}
		// 	}
		// }

		int a = fork();
		if(!a){

			// if (pipe_index){
			// 	piping(args_parsed, second);
			// 	return 0;
			// }
			execvp(args_parsed[0], args_parsed);

			return 0;
		}

		int p, status;
		p = wait(&status);
	}
}



int run(char *input){
	char **args = malloc(1024 * sizeof(char *));
	char* output = malloc(10000);
	char buf[9999];
	char* pipe_index = strchr(input, '|');
	if (pipe_index){
		char* first = input;
		pipe_index[0] = 0;
		char* second = &pipe_index[1];
		printf("first %s\n", first);
		printf("second %s\n", second);
		FILE *pipein = popen(first,"r");
		FILE *pipeout = popen(second, "w");
		fgets(buf, 9999, pipein);
		printf("hi\n");
	}

	int counter = 0;
	while(input){
		args[counter] = strsep(&input, ";");
		run_commands(parse_args(args[counter]));
		counter++;
	}
}

static void sighandler(int signo){
	if(signo == 2){
		printf("\nBombshell:｡･:*:･ﾟ’★,｡･:*:･ﾟ’☆ : ");
		fflush(stdout);
	}

}


int main(int argc, char const *argv[]){
	printf("==========BOMBSHELL==========\n");
	printf("	         \\|/\n"			);
	printf("	        .-*-\n"				);
	printf("	       / /|\\\n"			);
	printf("	      _L_\n"				);
	printf("	    ,\"   \".\n"			);
	printf("	(\\ /  O O  \\ /)\n"		);
	printf("	 \\|    _    |/\n"			);
	printf("	   \\  (_)  /\n"			);
	printf("	   _/.___,\\_\n"			);
	printf("	  (_/     \\_)\n"			);
	printf("\n");
	char *args = malloc(1024 * sizeof(args));
	while(1){
		// printf("\n");
		printf("Bombshell:｡･:*:･ﾟ’★,｡･:*:･ﾟ’☆ : ");
		fflush(stdout);
		signal(SIGINT, sighandler);
		fgets(args, 1023, stdin);
		// printf("%s\n", args);

		args[strlen(args) - 1] = 0;
		// char **args_parsed = parse_args(args);
		// printf("%s %s %s\n", args_parsed[0], args_parsed[1], args_parsed[2]);
		run(args);
	}

}
