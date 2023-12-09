#include "shell.h"

/**
 * handle_alias - Check if a command is a built-in command
 *
 * Description: This function checks if a given command is a built-in command
 * by comparing it with an array of predefined built-in commands.
 *
 * @cmd: The command to check.
 *
 * Return: 1 if the command is a built-in command, 0 otherwise.
 */

int handle_alias(char **cmd)
{
	NEW_ALIAS new_alias;
	char *alias_name = NULL;
	char *alias_val = NULL;
	int i;

	NEW_ALIAS *alias_arr = malloc(sizeof(NEW_ALIAS));

	if (cmd[0] && !cmd[1])
	{
		print_alias(alias_arr);
		return (0);
	}
	else
	{
		alias_name = strtok(cmd[1], "=");
		alias_val = strtok(NULL, "\n");

		for (i = 2; cmd[i]; i++)
		{
			_strcat(alias_val, " ");
			_strcat(alias_val, cmd[i]);
		}

		new_alias.name = _strdup(alias_name);
		new_alias.value = _strdup(alias_val);

		for (i = 0; alias_arr[i].name; i++)
			;

		alias_arr = realloc(alias_arr, (i + 2) * sizeof(NEW_ALIAS));

		if (!alias_arr)
		{
			free(new_alias.name);
			free(new_alias.value);
			return (-1);
		}

		alias_arr[i] = new_alias;

		return (0);
	}

	return (-1);
}


void print_alias(NEW_ALIAS *alias_arr)
{
	int i;

	for (i = 0; alias_arr[i].name; i++)
	{
		write(STDOUT_FILENO, alias_arr[i].name, _strlen(alias_arr[i].name));
		write(STDOUT_FILENO, "=", 1);
		write(STDOUT_FILENO, alias_arr[i].value, _strlen(alias_arr[i].value));
		write(STDOUT_FILENO, "\n", 1);
	}

	printf("hello world\n");
	printf("alias name = %s\n", alias_arr[0].name);
}
