#include "shell.h"


/**
 * check_if_builtin_cmd - Check if a command is a built-in command
 *
 * Description: This function checks if a given command is a built-in command
 * by comparing it with an array of predefined built-in commands.
 *
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in command, 0 otherwise.
 */

int check_if_builtin_cmd(char *cmd)
{
	/* Array of predefined built-in commands */
	char *builtin_cmd[] = { "exit", NULL };
	int i = 0;

	while (builtin_cmd[i])
	{
		/* Compare the given command with the current built-in command */
		if (_strcmp(builtin_cmd[i], cmd) == 0)
			return (1);

		i++;
	}

	/* The given command is not a built-in command */
	return (0);
}
