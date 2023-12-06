#include "shell.h"

/**
 * _unsetenv - Entry Point
 *
 * Description: This function checks if an environment variable
 * with the given name already exists. If it does not exist, it
 * dynamically allocates memory to create a new environment variable in
 * the format "name=value" and adds it to the current environment
 * variables. If the environment variable already exists
 * and the 'overwrite' flag is not set, the function does nothing.
 *
 * @envname: The name of the environment variable.
 *
 * Return: Returns 0 on success, or -1 on error,
 *
 */

int _unsetenv(char *envname)
{
	char *env_val = NULL;
	int i;

	env_val = _getenv(envname);

	/* If the environment variable does not exist */
	if (!env_val)
		return (0);

	/* Environment variable already exists, and 'overwrite' flag is set */

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], envname, _strlen(envname)) == 0)
		{
			for (; environ[i]; i++)
				environ[i] = environ[i + 1];

			free(env_val), env_val = NULL;
			return (0);
		}
	}

	free(env_val), env_val = NULL;
	return (0);
}
