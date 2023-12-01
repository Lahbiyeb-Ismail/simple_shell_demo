#include "shell.h"

/**
 * print_shell_error - Print an error message for a command not found
 *
 * Description: This function prints an error message to the standard
 * error output indicating that the specified command was not found.
 *
 * @shell_name: Name of the shell.
 * @cmd: Command that was not found.
 * @cmd_idx: Index of the command in the token array.
 *
 * Return : void
 */

void print_shell_error(char *shell_name, char *cmd, int cmd_idx)
{
	char *idx = _itoa(cmd_idx);
	char *msg = "not found\n";

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strlen(msg));

	free(idx);
}
