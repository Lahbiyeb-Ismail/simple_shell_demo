#include "shell.h"

/**
 * handle_comments - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 * @cmd_line: Array of tokens representing the command and its arguments.
 *
 * Return: The updated exit status after executing the built-in command.
 */

void handle_comments(char **cmd_line)
{
	int i;

	for (i = 0; (*cmd_line)[i]; i++)
	{
		if ((*cmd_line)[i] == '#')
		{
			if (i == 0)
			{
				free(*cmd_line);
				(*cmd_line) = NULL;
				return;
			}
			else
				return;
		}
	}
}

