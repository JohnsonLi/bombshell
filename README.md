Bombshell
by Johnson Li and Anthony Lam

Features:
	Forks and executes commands
	Parses multiple commands on one line
	Redirects using >, <
	Single Pipe

Attempted:
	Redirects using <<,>>
	Piping without popen()

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
	Inputs:  char *line 
	Returns: Array of strings where each entry is a token 
	separated by delim

	If line contains multiple tokens separated by delim, this 
	function will put each token into an array of strings
	====================*/

redirection.c
	Handles the redirection commands
	/*======== void redirect(char *input) ==========
	Inputs:  char *input
	Returns: void
	
	Run redirection command
	====================*/
pipe.c
	Handles the pipe commands
	/*======== void pipes2(char* input) ==========
	Inputs:  char *input
	Returns: void
	
	Run pipe command with popen()
	====================*/