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
 * @new_env: Pointer to the environment variable (can be updated during
 * command execution).
 *
 * Return: Returns 0 on success, or -1 on error,
 *
 */

int _setenv(char *envname, char *envval, int overwrite, char **new_env)
{
	char *env_val = NULL;

	env_val = _getenv(envname);

	/* Environment variable already exists, and 'overwrite' flag is set */
	set_modify_env(envname, envval, overwrite,
		new_env, env_val);

	if (!*new_env)
	{
		free(env_val), env_val = NULL;
		return (-1);
	}

	free(env_val), env_val = NULL;
	return (0);
}

/**
 * set_modify_env - Sets a new environment variable with the specified name
 * and value.
 *
 * Description: This function dynamically allocates memory to create a
 * string in the format "name=value" and adds it to the current
 * environment variables. The new environment variable is appended to the
 * end of the 'environ' array.
 *
 * @envname: The name of the environment variable.
 * @envval: The value to be assigned to the environment variable.
 * @new_env: Pointer to the environment variable (can be updated during
 * command execution).
 * @overwrite: Flag indicating whether to overwrite an existing variable.
 * @env_val: Flag indicating whether to overwrite an existing variable.
 *
 *
 * Return:
 * Returns 0 on success, or -1 on failure (memory allocation error or
 * environment variable not found and 'overwrite' is not set).
 *
 */

void set_modify_env(char *envname, char *envval, int overwrite,
	char **new_env, char *env_val)
{
	int env_count = 0;

	/* Find the number of existing environment variables */
	while (environ[env_count])
		env_count++;

	/* Construct the environment variable string: "name=value" */
	_strcpy(*new_env, envname);
	_strcat(*new_env, "=");
	_strcat(*new_env, envval);

	if (overwrite == 1 && env_val)
		while (environ[env_count])
		{
			if (_strncmp(environ[env_count], envname, _strlen(envname)) == 0)
			{
				_unsetenv(environ[env_count]);
				/* Modify the existing env variable with the new env */
				environ[env_count] = *new_env;
				return;
			}
			env_count++;
		}
	else
	{
		/* Add the new environment variable to the 'environ' array */
		environ[env_count] = *new_env;
		environ[env_count + 1] = NULL;
	}
}

