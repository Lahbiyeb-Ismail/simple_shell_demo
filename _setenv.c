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
	char *env_val = NULL;
	char *new_env = NULL;
	(void)overwrite;

	env_val = _getenv(name);

	if (!env_val)
	{
		new_env = set_new_env(name, value);

		if (env_val)
		{
			free(new_env);
			return (0);
		}

		return (-1);
	}


	free(env_val), env_val = NULL;
	return (0);
}


/**
 * set_new_env - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 * @name: Array of tokens representing the command and its arguments.
 * @value: An array of strings representing the command-line arguments.
 *
 * Return:  return zero on success, or -1 on error,
 *
 */

char *set_new_env(char *name, char *value)
{
	char *new_env = NULL;
	int env_count = 0;

	while (environ[env_count])
		env_count++;

	new_env = malloc(strlen(name) + strlen(value) + 2);

	if (!new_env)
		return (NULL);

	_strcpy(new_env, name);
	_strcat(new_env, "=");
	_strcat(new_env, value);

	environ[env_count] = new_env;
	environ[env_count + 1] = NULL;

	return (new_env);
}
