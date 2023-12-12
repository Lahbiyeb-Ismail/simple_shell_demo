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
	int exit_status = 0, cmd_idx = 0, is_comment = 1;
	(void)argc;

	do {
		/* Prompt user and read the command */
		cmd_line = read_command();
		is_comment = check_for_comments(cmd_line);
		if (is_comment == 1)
			cmd_line = handle_comments(cmd_line);

		if (!cmd_line && is_comment == 1)
			continue;
		else if (!cmd_line && is_comment == 0)
		{
			/* Print a new line befor exit if we are in the interactive mode */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			return (exit_status);
		}
		cmd_idx++;

		operator = check_for_operator(cmd_line);
		if (operator)
			handle_operators(argv, cmd_line,
				operator, &exit_status, cmd_idx);
		else
		{
			cmd = tokenize_command(cmd_line, " \t\n");
			if (!cmd)
				continue;
			process_command(cmd, argv, cmd_idx, &exit_status);
		}
	} while (1);
	free_memory(cmd);
}
