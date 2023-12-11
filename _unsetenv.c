#include "shell.h"

/**
 * _unsetenv - Unset (remove) an environment variable.
 *
 * Description: This function unset (remove) the specified environment
 * variable by searching for its name in the `environ` array.
 * If the environment variable is found, it is removed by shifting the elements
 * in the array. Memory allocated for the environment variable's
 * value is freed.
 * If the environment variable does not exist, the function returns 0.
 *
 * @envname: The name of the environment variable to unset.
 *
 * Return: 0 on success (environment variable removed), or -1 if the variable
 * does not exist or if an error occurs during the removal process.
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
