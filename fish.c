#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

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
		int a = fork();
		if(!a){
			execvp(args_parsed[0], args_parsed);
			return 0;
		}

		int p, status;
		p = wait(&status);
	}
}

int run(char *input){
	char **args = malloc(1024 * sizeof(char *));

	int counter = 0;
	while(input){
        args[counter] = strsep(&input, ";");
		run_commands(parse_args(args[counter]));
        counter++;
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

		fgets(args, 1023, stdin);
		// printf("%s\n", args);

		args[strlen(args) - 1] = 0;
		// char **args_parsed = parse_args(args);
		// printf("%s %s %s\n", args_parsed[0], args_parsed[1], args_parsed[2]);
		run(args);
	}

}
