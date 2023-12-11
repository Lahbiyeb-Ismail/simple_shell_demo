#include "shell.h"

/**
 * _setenv - Sets a new environment variable with the specified name and value.
 *
 * Description: This function checks if an environment variable
 * with the given name already exists. If it does not exist, it
 * dynamically allocates memory to create a new environment variable in
 * the format "name=value" and adds it to the current environment
 * variables. If the environment variable already exists
 * and the 'overwrite' flag is not set, the function does nothing.
 *
 * @envname: The name of the environment variable.
 * @envval: The value to be assigned to the environment variable.
 * @overwrite: The value to be assigned to the environment variable.
 *
 * Return: Returns 0 on success, or -1 on error,
 *
 */

int _setenv(char *envname, char *envval, int overwrite)
{
	char **ep;
	size_t size;
	char *cur_env;
	char *new_env;

	for (ep = environ; *ep != NULL; ++ep)
	{
		cur_env = *ep;
		size = _strlen(envname);

		if (_strncmp(cur_env, envname, size) == 0 && cur_env[size] == '=')
		{
			if (overwrite == 0)
				return (0);

			break;
		}
	}

	new_env = malloc(_strlen(envname) + _strlen(envval) + 2);

	if (new_env == NULL)
		return (-1);

	_strcpy(new_env, envname);
	_strcat(new_env, "=");
	_strcat(new_env, envval);

	if (*ep != NULL)
		free(*ep);

	*ep = new_env;

	return (0);
}
