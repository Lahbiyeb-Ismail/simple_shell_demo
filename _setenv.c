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
	int env_count = 0;
	(void)overwrite;

	env_val = _getenv(name);

	if (!env_val)
	{
		while (environ[env_count])
			env_count++;

		new_env = malloc(strlen(name) + strlen(value) + 2);

		if (new_env)
		{
			_strcpy(new_env, name);
			_strcat(new_env, "=");
			_strcat(new_env, value);

			environ[env_count] = new_env;
			environ[env_count + 1] = NULL;

			free(env_val), env_val = NULL;
			return (0);
		}
	}
	else
		printf("env value: %s\n", env_val);


	free(env_val), env_val = NULL;
	free(new_env), new_env = NULL;
	return (0);

}



