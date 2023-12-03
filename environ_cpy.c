#include "shell.h"

/**
 * make_environ_cpy - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 *
 * Return: environ_cpy
 *
 */

char **make_environ_cpy(void)
{
	int env_count = 0;
	char **environ_cpy = NULL;


	while (environ[env_count])
		env_count++;

	environ_cpy = malloc(sizeof(char *) + (env_count + 1));

	for (env_count = 0; environ[env_count]; env_count++)
		environ_cpy[env_count] = _strdup(environ[env_count]);

	environ_cpy[env_count] = NULL;

	return (environ_cpy);
}


/**
 * create_env - creates a structure for the copy
 *	of Environ

 * Return: the new structure
 */

New_env *create_env(void)
{
	New_env *env = malloc(sizeof(New_env));

	env->env_var = make_environ_cpy();

	return (env);
}
