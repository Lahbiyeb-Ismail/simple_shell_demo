#include "shell.h"

/**
 * print_shell_error - Print a formatted error message to standard error
 *
 * Description: This function prints a formatted error message to the standard
 * error output. The message includes information such as the shell name,
 * command index, command name, error message,
 * and an optional command argument.
 *
 * @shell_name: The name of the shell.
 * @cmd_idx: The index of the command in the token array.
 * @cmd: Array of tokens representing the command and its arguments.
 * @err_msg: The error message to be displayed.
 *
 * Return: void
 */

void print_shell_error(char *shell_name, int cmd_idx, char **cmd,
	char *err_msg)
{
	char *idx = _itoa(cmd_idx);

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_msg, _strlen(err_msg));

	if (cmd[1])
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
	}

	write(STDERR_FILENO, "\n", 1);

	free_memory(cmd);
	free(idx);
}
