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

/* TODO: FIX MEMORY ALLOCATION LEAK*/
int _setenv(char *envname, char *envval, int overwrite, char **new_env)
{
	char *env_val = NULL;

	env_val = _getenv(envname);

	/* If the environment variable does not exist */
	if (!env_val)
		set_new_env(envname, envval, new_env);
	/* Environment variable already exists, and 'overwrite' flag is set */
	else if (overwrite)
		modify_env(envname, envval, overwrite, new_env);

	if (!*new_env)
		return (-1);

	free(env_val), env_val = NULL;
	return (0);
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

void set_new_env(char *envname, char *envval, char **new_env)
{
	int env_count = 0;

	/* Find the number of existing environment variables */
	while (environ[env_count])
		env_count++;

	/* Construct the environment variable string: "name=value" */
	construct_env_str(envname, envval, new_env);

	if (!*new_env)
		return;

	/* Add the new environment variable to the 'environ' array */
	environ[env_count] = *new_env;
	environ[env_count + 1] = NULL;
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

void modify_env(char *envname, char *envval, int overwrite, char **new_env)
{
	int i = 0;

	/* Construct the environment variable string: "name=value" */
	construct_env_str(envname, envval, new_env);

	if (!*new_env)
		return;

	while (environ[i])
	{
		if (_strncmp(environ[i], envname, _strlen(envname)) == 0)
		{
			if (overwrite == 1)
			{
				_unsetenv(environ[i]);
				/* Modify the existing env variable with the new env */
				environ[i] = *new_env;
				return;
			}

			free(*new_env), *new_env = NULL;
			return;
		}
		i++;
	}
}


/**
 * construct_env_str - Constructs a formatted string for an env variable.
 *
 * Description:
 * This function dynamically allocates memory to create a string in the format
 * "name=value" for a given environment variable. The caller is responsible for
 * freeing the allocated memory when it is no longer needed.
 *
 * @new_env: Pointer to a char pointer that will store the newly constructed
 * env string.
 * @envname: The name of the environment variable.
 * @envval: The value to be assigned to the environment variable.
 *
 * Return:
 * Returns a pointer to the dynamically allocated string containing the
 * environment variable in the format "name=value". Returns NULL if memory
 * allocation fails.
 */

void construct_env_str(char *envname, char *envval, char **new_env)
{
	char *new_env_cpy = NULL;
	/* Allocate memory for the new environment variable */
	new_env_cpy = malloc(_strlen(envname) + _strlen(envval) + 2);

	/* Check if memory allocation was successful */
	if (!new_env_cpy)
		return;

	/* Construct the environment variable string: "name=value" */
	_strcpy(new_env_cpy, envname);
	_strcat(new_env_cpy, "=");
	_strcat(new_env_cpy, envval);

	*new_env = _strdup(new_env_cpy);
	free(new_env_cpy);
}
