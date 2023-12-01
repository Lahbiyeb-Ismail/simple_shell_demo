#include "shell.h"

/**
 * _getenv - Execute the command with its arguments
 *
 * Description: This function creates a child process to execute
 * the command specified by the array of tokens using execve.
 *
 * @name: Array of tokens representing the command and its arguments.
 *
 * Return: 0 on success, -1 on failure.
 *
*/


char *_getenv(char *name)
{
	char *env_cpy, *env_key, *env_val, *env;
	int i = 0;

	if (name == NULL || environ == NULL)
		return (NULL);

	for (; environ[i]; i++)
	{
		env_cpy = _strdup(environ[i]);
		if (!env_cpy)
			return (NULL);

		env_key = strtok(env_cpy, "=");

		if (_strcmp(env_key, name) == 0)
		{
			env_val = strtok(NULL, "\n");

			if (env_val != NULL)
			{
				env = _strdup(env_val);
				free(env_cpy);
				return (env);
			}
			else
			{
				free(env_cpy);
				return (NULL);
			}
		}

		free(env_cpy);
	}

	return (NULL);
}

