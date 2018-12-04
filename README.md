# Bombshell  💣💣💣
### by Johnson Li and Anthony Lam

## Features:
	- Forks and executes commands
	- Parses multiple commands on one line with ;
	- Single redirect using > or <
	- Single Pipe

## Attempted:
	- Multiple redirects and pipes.
	- >> redirect.
	- Spaces between ;, >, <, | (It didn't work the first time and we decided it wasn't important enough to fix)

## Bugs:  
	- Fork bomb when piping to an invalid comamnd. Ex: "ls|gree hi" (actually a feature of our BOMBshell)
	- Sometime have to run exit multiple times to exit, due to some stray fork
	- pipes and redirects cannot be run with space. Ex: ls|wc works, ls | wc doesn't
	- After a redirect, some commands will break. Ex: after ls>hi, ls will not be able to run. But ls -l can.
	
## Files & Function Headers:
#### shell.c: Handles taking input from the shell  
	
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
	
	/*======== int main() ==========
	Responsible displaying prompt for taking in user input and passing it to run(char *input)
	====================*/
	
#### pipe.c: Runs the pipe commands

	/*======== void pipes2(char* input) ==========
	Inputs:  char* input
	Returns: void
	Runs the pipe commands, it's called pipes2 because previous versions borked.
	====================*/
	
#### redirect.c: Runs redirect commands 

	/*======== void redirect(char* input) ==========
	Inputs:  char* input
	Returns: int
	Redirects based on > or <.
	====================*/

got a weird file and it's cool so we're keeping it.
