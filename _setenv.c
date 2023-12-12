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
	size_t name_len = strlen(envname);
	size_t val_len = strlen(envval);
	size_t env_len;
	char **new_environ = NULL;
	char *new_val = NULL;


	/* Search for the environment variable in the environ array */
	for (ep = environ; *ep != NULL; ++ep)
	{
		if (!strncmp(*ep, envname, name_len) && (*ep)[name_len] == '=')
		{
				/* The environment variable exists */
			if (overwrite)
			{
					/* Overwrite the value of the environment variable */
				new_val = malloc(name_len + val_len + 2);

				if (new_val == NULL)
				{
					return (-1); /* return -1 in case of error */
				}
				strcpy(new_val, envname);
				strcat(new_val, "=");
				strcat(new_val, envval);
				*ep = new_val;
			}
			return 0;
		}
	}

	/* The environment variable does not exist, create a new one */
	env_len = ep - environ;
	new_environ = malloc((env_len + 2) * sizeof(char *));
	new_val = malloc(name_len + val_len + 2);

	if (new_environ == NULL)
	{
		return (-1); /* return -1 in case of error */
	}
	memcpy(new_environ, environ, env_len * sizeof(char *));

	if (new_val == NULL)
	{
		free(new_environ);
		return (-1); /* return -1 in case of error */
	}
	strcpy(new_val, envname);
	strcat(new_val, "=");
	strcat(new_val, envval);
	new_environ[env_len] = new_val;
	new_environ[env_len + 1] = NULL;
	environ = new_environ;

	return (0);
}
