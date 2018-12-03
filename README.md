Bombshell
by Johnson Li and Anthony Lam

Features:
	Forks and executes commands
	Parses multiple commands on one line
	Redirects using >, <
	Single Pipe

Attempted:
	The following did not end up working, but have been left in the code, commented out.

Bugs:
	Shell breaks after running a pipe command
	Sometime have to run exit multiple times to exit
	
Files & Function Headers:
shell.c
	Handles taking input from the shell
	/*======== void sighandler(int signo) ==========
	Inputs:  int signo
	Returns: void
	
	Checks for the SIGINT and ignores it
	====================*/

	/*======== char **parse_args(char *input, char **buffer) ==========
	Inputs:  char *input, char **buffer
	Returns: A pointer to a two array of the command

	Separates the input by spaces and returns a pointer to the 2D array
	====================*/

	/*======== int run_commands(char *input) ==========
	Inputs:  char *input
	Returns: 0

	Runs the command and runs other functions depending on if it has a redirect or pipe
	====================*/

	/*======== void run(char *input) ==========
	Inputs:  char *input
	Returns: void

	Separates the input at semicolons and runs the individual commands
	====================*/

pipe.c
	Runs the pipe commands
	/*======== void pipes2(char* input) ==========
	Inputs:  char* input
	Returns: void
	
	Runs the pipe commands
	====================*/
pipe.c
	Runs the pipe commands
	/*======== void pipes2(char* input) ==========
	Inputs:  char* input
	Returns: void
	
	Runs the pipe commands
	====================*/
magical.c
UNOCORNS! 