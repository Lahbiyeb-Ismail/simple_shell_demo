#include "shell.h"

/**
 * _setenv - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 * @name: Array of tokens representing the command and its arguments.
 * @value: An array of strings representing the command-line arguments.
 * @overwrite: The exit status of the previous command.
 *
 * Return:  return zero on success, or -1 on error,
 *
 */

int _setenv(char *name, char *value, int overwrite)
{
	int i = 0;
	char *new_env = NULL;
	(void)overwrite;

	if (!name || !value)
		return (-1);

	while (environ[i])
		i++;

	new_env = malloc(_strlen(name) + _strlen(value) + 2);

	if (!new_env)
		return (-1);

	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);

	environ[i] = new_env;
	environ[i + 1] = NULL;

	return (0);
}



