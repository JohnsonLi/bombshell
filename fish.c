#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

char **parse_args(char *input){
	char **args = malloc(1024 * sizeof(char *));

	int counter = 0;
	while(input){
        args[counter] = strsep(&input, " ");
        counter++;
	}

	return args;
}


int main(int argc, char const *argv[]){
	printf("==========SHELLFISH==========\n");

	char *args = malloc(1024 * sizeof(args));
	while(1){
		// printf("\n");
		printf("shellfish>$>$>$>$@@@ ");
		fflush(stdout);

		fgets(args, sizeof(args), stdin);
		// read(STDIN_FILENO, args, 1000);
		args[strlen(args) - 1] = 0;
		char **args_parsed = parse_args(args);
		printf("%s %s\n", args_parsed[0], args_parsed[1]);
		// printf("%ld\n", sizeof(args_parsed));
		// int i;
		// for(i = 0; i < sizeof(args_parsed); i++){
		// 	printf("%s\n", args_parsed[i]);
		// }

		execvp(args_parsed[0], args_parsed);
	}

}
