#include "shell.h"

/**
 * print_env - Print environment variables to the standard output
 *
 * Description: This function prints the environment variables to the
 * standard output, followed by a newline character.
 * After printing the environment variables, the function frees the memory
 * allocated for the command and the new environment.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 *
 * Return: 0 on success
 */

int print_env(char **cmd)
{
	unsigned int i = 0;

	/* Iterate through the environment variables and print each one */
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	/* Free memory allocated for the command */
	free_memory(cmd);

	return (0);
}

