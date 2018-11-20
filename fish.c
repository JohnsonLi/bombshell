#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char const *argv[]){
	printf("==========SHELLFISH==========\n");


	char *args = malloc(1000 * sizeof(args));
	printf("shellfish>>>>@ ");
	while(1){
		// printf("\n");
		printf("shellfish>>>>@ \n");
		// read(STDIN_FILENO, args, 1000);
		// args[999] = 0;
		// printf("%s\n", args);
	}

}