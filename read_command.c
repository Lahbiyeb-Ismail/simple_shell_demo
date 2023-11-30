#include "shell.h"

/**
 * read_command - Reads a command from the standard input.
 *
 * Description: This function uses getline to read a line of input from
 * the user.
 * The memory for the input line is dynamically allocated based on the
 * size of the input.
 *
 * Return: A dynamically allocated string containing the user's input command.
 *
*/

char *read_command(void)
{
	/* The buffer to store the user's input */
	char *cmd = NULL;
	/* The initial size of the buffer */
	size_t buffer_size = 0;

	/* Attempt to read a line of input from the user */
	if (getline(&cmd, &buffer_size, stdin) == -1)
	{
		perror("Failed to read command");
		exit(EXIT_FAILURE);
	}

	return (cmd);
}
