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
	(void)overwrite;

	env_val = _getenv(envname);

	/* If the environment variable does not exist */
	if (!env_val)
	{
		if (set_new_env(envname, envval) == -1)
			return (-1);

		free(env_val), env_val = NULL;
		/* Successfully set the new environment variable */
		return (0);
	}

	 /* Environment variable already exists, and 'overwrite' flag is set */
		/* TODO: Update the existing environment variable with the new value*/
		/* For now, we free the existing value and return success */
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
 * Return: A pointer to the dynamically allocated string containing the
 *         environment variable in the format "name=value".
 * Returns NULL if memory allocation fails.
 *
 */

int set_new_env(char *envname, char *envval)
{
	char *new_env = NULL;
	int env_count = 0;

	/* Find the number of existing environment variables */
	while (environ[env_count])
		env_count++;

	/* Allocate memory for the new environment variable */
	new_env = malloc(_strlen(envname) + _strlen(envval) + 2);

	/* Check if memory allocation was successful */
	if (!new_env)
		return (-1);

	/* Construct the environment variable string: "name=value" */
	_strcpy(new_env, envname);
	_strcat(new_env, "=");
	_strcat(new_env, envval);

	/* Add the new environment variable to the 'environ' array */
	environ[env_count] = new_env;
	environ[env_count + 1] = NULL;

	return (0);
}
