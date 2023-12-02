#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 *
 * Description: This function retrieves the value of an environment variable
 * given its name. It searches through the environment variables until it finds
 * a match for the specified name and returns the corresponding value. If the
 * name is not found or if memory allocation fails during the process, the
 * function returns NULL.
 *
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable, or NULL if the
 * variable is not found or if memory allocation fails.
 */

char *_getenv(char *name)
{
	char *env_cpy, *env_key, *env_val, *env;
	int i;

	/* Check for NULL name or NULL environ */
	if (name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		/* Duplicate the current environment variable for processing */
		env_cpy = _strdup(environ[i]);
		if (!env_cpy)
			return (NULL);

		/* Tokenize the environment variable to extract the key */
		env_key = strtok(env_cpy, "=");

		/* Check if the key matches the specified name */
		if (_strcmp(env_key, name) == 0)
		{
			/* Tokenize to get the value part */
			env_val = strtok(NULL, "\n");

			/* free the duplicated environment variable and return NULL */
			if (!env_val)
			{
				free(env_cpy);
				return (NULL);
			}

			/* Duplicate the value and free the duplicated environment variable */
			env = _strdup(env_val);
			free(env_cpy);
			return (env);
		}

		free(env_cpy);
	}

	return (NULL);
}

