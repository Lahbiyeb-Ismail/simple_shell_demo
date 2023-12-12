#include "shell.h"

/**
 * read_command - Reads a command line from the specified stream.
 *
 * Description: This function reads a line of input from the user using the
 * getline function. It dynamically allocates memory to store the input and
 * returns a pointer to the buffer. The caller is responsible for freeing
 * the allocated memory when it is no longer needed.
 * If the argc is not 2, it also prints the shell prompt character ('$')
 * followed by a space before reading the input.
 * The caller should check the return value for NULL to handle potential
 * errors in input or memory allocation.
 *
 * @stream: The input stream (e.g., stdin) from which to read the command line.
 * @argc: The number of command-line arguments.
 *
 * Return: A pointer to the dynamically allocated buffer containing the
 * user's input.
 * Or NULL if an error occurs or if the end of the stream is reached.
 *
*/

char *read_command(FILE *stream, int argc)
{
	/* The buffer to store the user's input */
	char *cmd_line = NULL;
	/* The initial size of the buffer */
	size_t buffer_size = 0;

		/*This function is for print the '$' character followed by a space.*/
	if (argc != 2)
		print_shell_prompt();

		/* Attempt to read a line of input from the user */
	if (getline(&cmd_line, &buffer_size, stream) == -1)
	{
		free(cmd_line);
		return (NULL);
	}

	return (cmd_line);
}



