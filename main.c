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

		if (operator)
		{
			int i;

			multi_cmd = tokenize_command(cmd_line, operator);

			for (i = 0; multi_cmd[i]; i++)
			{
					/* Tokenize (split) the command and get the array of tokens */
				cmd = tokenize_command(multi_cmd[i], " \t\n");

				if (!cmd)
					continue;

				if (check_if_builtin_cmd(cmd[0]))
					exit_status = handle_builtin_cmd(cmd, argv, &exit_status, cmd_idx);
				else
				/* Execute the command and get the exit status */
					exit_status = exec_command(cmd, argv, cmd_idx);
			}
		}
		else
		{
				/* Tokenize (split) the command and get the array of tokens */
			cmd = tokenize_command(cmd_line, " \t\n");

			if (!cmd)
				continue;

			if (check_if_builtin_cmd(cmd[0]))
				exit_status = handle_builtin_cmd(cmd, argv, &exit_status, cmd_idx);
			else
			/* Execute the command and get the exit status */
				exit_status = exec_command(cmd, argv, cmd_idx);
		}
	} while (1);

	free(cmd_line);
	free_memory(cmd);
}
