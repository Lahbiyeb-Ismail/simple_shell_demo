#include "shell.h"

/**
 * print_file_error - Print a formatted error message to standard error
 *
 * Description: This function prints a formatted error message to the standard
 * error output. The message includes information such as the shell name,
 * command index, command name, error message,
 * and an optional command argument.
 *
 * @shell_name: The name of the shell.
 * @cmd_idx: The index of the command in the token array.
 * @file_name: Array of tokens representing the command and its arguments.
 *
 * Return: void
 */

void print_file_error(char *shell_name, int cmd_idx, char *file_name)
{
	char *idx = _itoa(cmd_idx);
	char *err_msg_1 = "cannot open ";
	char *err_msg_2 = "No such file";

	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_msg_1, _strlen(err_msg_1));
	write(STDERR_FILENO, file_name, _strlen(file_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_msg_2, _strlen(err_msg_2));
	write(STDERR_FILENO, "\n", 1);

	free(idx);
}
