#include "shell.h"

/**
 * change_dir - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 *
 * Return: The updated exit status after executing the built-in command.
 */

int change_dir(char **cmd, char **new_env)
{
	int status = 0;
	char *dir = NULL;
	char *curr_dir = NULL;
	char *old_pwd = NULL, *old_pwd_val = NULL;
	char *home_env = NULL, *home_val = NULL;

	curr_dir = getcwd(curr_dir, 0);

	/* Get the prev working dir from the environment variables ('OLDPWD') */
	old_pwd = _getenv("OLDPWD");
	old_pwd_val = old_pwd ? strtok(old_pwd, "=") : curr_dir;

	/* Get the user's home directory from the environment variables */
	home_env = _getenv("HOME");
	home_val = home_env ? strtok(home_env, "=") : NULL;

	if (!curr_dir)
	{
		perror("getcwd");
		free_cd_memory(curr_dir, old_pwd, home_env);
		return (-1);
	}

	if (!cmd[1])
		dir = cd_home(curr_dir, home_val, new_env);
	else if (_strcmp(cmd[1], "-") == 0)
		dir = cd_prev(curr_dir, old_pwd_val, new_env);
	else
		dir = cd_to(cmd[1], curr_dir, new_env);

	status = chdir(dir);

	free_cd_memory(curr_dir, old_pwd, home_env);
	return (status);
}

/**
 * cd_home - Change the current working directory to the user's home directory.
 *
 * Description:
 * This function retrieves the user's home directory from the environment
 * variables, changes the current working directory to that directory, and
 * updates the environment variables 'PWD' and 'OLDPWD' accordingly.
 *
 * @curr_dir: The current working dir before changing to the home directory.
 * @home_val: The user's home (root) working directory.
 *
 * Return:
 * Returns a pointer to the user's home dir on success, or NULL on failure.
 */

char *cd_home(char *curr_dir, char *home_val, char **new_env)
{
	char *dir = NULL;

	/* If the !home_val Set the target directory to the user's curr_dir */
	if (!home_val)
	{
		dir = curr_dir;
		/* Update the environment variables 'PWD' and 'OLDPWD' */
		_setenv("PWD", dir, 1, new_env);
		_setenv("OLDPWD", dir, 1, new_env);
	}
	/* Set the target directory to the user's Home dir */
	else
	{
		dir = home_val;
		/* Update the environment variables 'PWD' and 'OLDPWD' */
		_setenv("PWD", dir, 1, new_env);
		_setenv("OLDPWD", curr_dir, 1, new_env);
	}

	return (dir);
}


/**
 * cd_prev - Change the current working dir to the previous working dir.
 *
 * Description:
 * This function retrieves the previous working directory ('OLDPWD') from the
 * environment variables, changes the current working directory to that dir,
 * and updates the environment variables 'PWD' and 'OLDPWD' accordingly.
 *
 * @curr_dir: The current working dir before changing to the previous dir.
 * @old_pwd_val: The value of the 'OLDPWD' environment variable.
 *
 * Return: A pointer to the prev working dir on success, or NULL on failure.
 */

char *cd_prev(char *curr_dir, char *old_pwd_val, char **new_env)
{

	char *dir = NULL;

	/* Set the target directory to the previous working directory */
	dir = old_pwd_val;

	/* Print the target directory to the standard output */
	write(STDOUT_FILENO, dir, _strlen(dir));
	write(STDOUT_FILENO, "\n", 1);

	/* Update the environment variables 'PWD' and 'OLDPWD' */
	_setenv("PWD", dir, 1, new_env);
	_setenv("OLDPWD", curr_dir, 1, new_env);

	return (dir);
}

/**
 * cd_to - Change the current working directory to a specified path.
 *
 * Description:
 * This function changes the current working directory to the specified 'path'
 * and updates the environment variables 'PWD' and 'OLDPWD' accordingly.
 *
 * @path: The target path to change the current working directory to.
 * @curr_dir: The current working directory before the change.
 *
 * Return: A pointer to the specified path on success, or NULL on failure.
 */

char *cd_to(char *path, char *curr_dir, char **new_env)
{
	char *dir = path;

	/* Update the environment variable 'OLDPWD' */
	_setenv("OLDPWD", _getenv("PWD"), 1, new_env);
	/* Set the current working directory to the specified path */
	_setenv("PWD", curr_dir, 1, new_env);

	return  (dir);
}

/**
 * free_cd_memory - Free memory associated with current directory, old working
 * directory, and home environment.
 *
 * Description:
 * This function frees the memory associated with the provided strings
 *
 * @curr_dir: Pointer to the current working directory string.
 * @old_pwd: Pointer to the old working directory string.
 * @home_env: Pointer to the home environment string.
 *
 */

void free_cd_memory(char *curr_dir, char *old_pwd, char *home_env)
{
	free(curr_dir);
	free(old_pwd);
	free(home_env);
}
