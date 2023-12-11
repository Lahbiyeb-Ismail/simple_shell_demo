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
	char *cmd_line = NULL;
	/* The initial size of the buffer */
	size_t buffer_size = 0;

	/*This function is for print the '$' character followed by a space.*/
	print_shell_prompt();

	/* Attempt to read a line of input from the user */
	if (getline(&cmd_line, &buffer_size, stdin) == -1)
	{
		free(cmd_line);
		return (NULL);
	}

	if (check_for_comments(cmd_line) == 1)
		return (handle_comments(cmd_line));

	return (cmd_line);
}



