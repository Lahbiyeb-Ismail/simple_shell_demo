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
	char *env_val = NULL;
	int status;

	env_val = _getenv(envname);

	/* If the environment variable does not exist */
	if (!env_val)
		status = set_new_env(envname, envval);
	/* Environment variable already exists, and 'overwrite' flag is set */
	else
		status = modify_env(envname, envval, overwrite);

	free(env_val), env_val = NULL;
	return (status);
}

/**
 * set_new_env - Sets a new environment variable with the specified name
 * and value.
 *
 * Description: This function dynamically allocates memory to create a
 * string in the format "name=value" and adds it to the current
 * environment variables. The new environment variable is appended to the
 * end of the 'environ' array.
 *
 * @envname: The name of the environment variable.
 * @envval: The value to be assigned to the environment variable.
 *
 * Return:
 * Returns 0 on success, or -1 on failure (memory allocation error or
 * environment variable not found and 'overwrite' is not set).
 *
 */

int set_new_env(char *envname, char *envval)
{
	char *new_env = NULL;
	int env_count = 0;

	/* Find the number of existing environment variables */
	while (environ[env_count])
		env_count++;

	/* Construct the environment variable string: "name=value" */
	new_env = construct_env_str(envname, envval);

	if (!new_env)
		return (-1);

	/* Add the new environment variable to the 'environ' array */
	environ[env_count] = new_env;
	environ[env_count + 1] = NULL;

	return (0);
}

/**
 * modify_env - Modifies an existing environment variable.
 *
 * Description:
 * This function searches for an environment variable with the specified name.
 * If found, it updates the value with the new value (if 'overwrite' is set),
 * or does nothing (if 'overwrite' is not set).
 *
 * @envname: The name of the environment variable.
 * @envval: The value to be assigned to the environment variable.
 * @overwrite: Flag indicating whether to overwrite an existing variable.
 *
 * Return:
 * Returns 0 on success, or -1 on failure (memory allocation error or
 * environment variable not found and 'overwrite' is not set).
 */

int modify_env(char *envname, char *envval, int overwrite)
{
	char *new_env = NULL;
	int i = 0;

	/* Construct the environment variable string: "name=value" */
	new_env = construct_env_str(envname, envval);

	if (!new_env)
		return (-1);

	while (environ[i])
	{
		if (_strncmp(environ[i], envname, _strlen(envname)) == 0)
		{
			if (overwrite)
			{
				free(environ[i]), environ[i] = NULL;

				/* Modify the existing env variable with the new env */
				environ[i] = new_env;
				return (0);
			}

			free(new_env), new_env = NULL;
			return (0);
		}
		i++;
	}

	free(new_env), new_env = NULL;
	return (-1);
}

/**
 * construct_env_str - Constructs a formatted string for an env variable.
 *
 * Description:
 * This function dynamically allocates memory to create a string in the format
 * "name=value" for a given environment variable. The caller is responsible for
 * freeing the allocated memory when it is no longer needed.
 *
 * @envname: The name of the environment variable.
 * @envval: The value to be assigned to the environment variable.
 *
 * Return:
 * Returns a pointer to the dynamically allocated string containing the
 * environment variable in the format "name=value". Returns NULL if memory
 * allocation fails.
 */

char *construct_env_str(char *envname, char *envval)
{
	char *new_env = NULL;

	/* Allocate memory for the new environment variable */
	new_env = malloc(_strlen(envname) + _strlen(envval) + 2);

	/* Check if memory allocation was successful */
	if (!new_env)
		return (NULL);

	/* Construct the environment variable string: "name=value" */
	_strcpy(new_env, envname);
	_strcat(new_env, "=");
	_strcat(new_env, envval);

	return (new_env);
}
