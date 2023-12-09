#include "shell.h"

/**
	* main - Entry Point
	*
	* Description: This function serves as the entry point for the program.
	* It prompts the
	* user to enter a command, reads the command, tokenize it into an array
	* of tokens, and then performs any additional processing required.
	* Finally, it frees the allocated memory before exiting.
	*
	* @argc: The number of command-line arguments.
	* @argv: An array of strings representing the command-line arguments.
	*
	* Return: 0 in success execution
	*
*/

int main(int argc, char **argv)
{
	/* Buffer to store the user's input cmd */
	char *cmd_line = NULL;
	char *operator = NULL;
	/* Array to store the tokens of the cmd */
	char **cmd = NULL;
	char **multi_cmd = NULL;
	int exit_status = 0, cmd_idx = 0;
	(void)argc;

	do {
		/* Prompt user and read the command */
		cmd_line = read_command();
		if (!cmd_line)
		{
			/* Print a new line befor exit if we are in the interactive mode */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			return (exit_status);
		}
		cmd_idx++;

		/* TODO: FIX THE MEMORY ALLOCATION LEAK */
		operator = check_for_operator(cmd_line);

			/* TODO: TEST WITH _strdup(cmd_line)*/
		if (operator)
		{
			multi_cmd = tokenize_command(cmd_line, operator);
			handle_operators(argv, multi_cmd, cmd_line,
				operator, &exit_status, cmd_idx);
		}

		else
		{
				/* Tokenize (split) the command and get the array of tokens */
			cmd = tokenize_command(cmd_line, " \t\n");
			if (!cmd)
				continue;
			process_command(cmd, argv, cmd_idx, &exit_status);
		}
	} while (1);
	free_memory(multi_cmd);
	free_memory(cmd);
}
