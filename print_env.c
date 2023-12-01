#include "shell.h"

/**
 * print_env - Print environment variables to the standard output
 *
 * Description: This function prints the environment variables to the
 * standard output, followed by a newline character. It then frees the
 * memory allocated for the command.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @exit_status: The exit status to be used when exiting the shell.
 *
 *
 * Return: void
 */

void print_env(char **cmd, int *exit_status)
{
	unsigned int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	/* Free memory allocated for the command */
	free_memory(cmd);

	(*exit_status) = 0;
}

