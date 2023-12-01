#include "shell.h"

/**
 * exit_shell - Exit the shell
 *
 * Description: This function frees the memory allocated for the command
 * and exits the shell with the provided exit status.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @exit_status: The exit status of the previous command.
 * @cmd_idx: Index of the command in the token array.
 *
 * Return: void
 */

void exit_shell(char **cmd, char **argv, int *exit_status, int cmd_idx)
{
	int exit_val = (*exit_status);
	char *idx = _itoa(cmd_idx);
	char *msg = "Illegal number";

	if (cmd[1])
	{
		if (is_positive_num(cmd[1]))
			exit_val = _atoi(cmd[1]);
		else
		{
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _strlen(idx));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, msg, _strlen(msg));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);

			free(idx);
			free_memory(cmd);

			(*exit_status) = 2;
			return;
		}
	}

	/* Free memory allocated for the command */
	free(idx);
	free_memory(cmd);

	/* Exit the shell with the provided exit status  */
	exit(exit_val);
}
