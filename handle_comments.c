#include "shell.h"

/**
 * handle_comments - Handles comments in a command line by removing everything
 * from '#' onward.
 *
 * Description: This function takes a command line as input, searches for
 * the '#' character, and removes the '#' and everything after it if certain
 * conditions are met.
 * If '#' is found at the beginning of the command line, the function frees the
 * original memory and returns NULL to signal that the entire command line
 * should be ignored.
 * If '#' is preceded by a space, tab, or semicolon, the function creates a new
 * command line without the commented portion and returns a dynamically
 * allocated string for the modified command line.
 *
 * @cmd_line: The input command line.
 *
 * Return: A dynamically allocated string with comments removed, or NULL if the
 * entire command line should be ignored.
 */

char *handle_comments(char *cmd_line)
{
	int i, new_size;
	char *new_cmd_line = NULL;

	for (i = 0; cmd_line[i]; i++)
	{
		if (cmd_line[i] == '#')
		{
			if (i == 0)
			{
				free(cmd_line);
				return (NULL);
			}
			else if (cmd_line[i - 1] == ' ' || cmd_line[i - 1] == '\t' ||
				cmd_line[i - 1] == ';')
				new_size = i;
		}
	}

	if (new_size != 0)
	{
		new_cmd_line = malloc(sizeof(char) * (new_size + 1));

		if (new_cmd_line)
		{
			i = 0;
			for (; i < new_size; i++)
				new_cmd_line[i] = cmd_line[i];

			new_cmd_line[i] = '\0';
		}
	}

	return (new_cmd_line);
}

