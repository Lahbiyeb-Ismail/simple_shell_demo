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

int change_dir(char **cmd)
{
	int status = 0;
	char *dir = NULL;
	char *curr_dir = NULL;

	curr_dir = getcwd(curr_dir, 0);

	if (!curr_dir)
	{
		perror("getcwd");
		return (-1);
	}

	if (!cmd[1])
		dir = cd_home(curr_dir);
	else if (_strcmp(cmd[1], "-") == 0)
		dir = cd_prev(curr_dir);
	else
		dir = cd_to(cmd[1], curr_dir);

	status = chdir(dir);
	free(curr_dir);

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
 *
 * Return:
 * Returns a pointer to the user's home dir on success, or NULL on failure.
 */

char *cd_home(char *curr_dir)
{
	char *dir = NULL;
	char *home_env = NULL, *home_val = NULL;

	/* Get the user's home directory from the environment variables */
	home_env = _getenv("HOME");
	home_val = home_env ? strtok(home_env, "=") : NULL;

	/* Set the target directory to the user's home directory */
	dir = home_val;

	/* Update the environment variables 'PWD' and 'OLDPWD' */
	_setenv("PWD", dir, 1);
	_setenv("OLDPWD", curr_dir, 1);

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
 *
 * Return: A pointer to the prev working dir on success, or NULL on failure.
 */

char *cd_prev(char *curr_dir)
{

	char *old_pwd = NULL, *old_pwd_val = NULL;
	char *dir = NULL;

	/* Get the prev working dir from the environment variables ('OLDPWD') */
	old_pwd = _getenv("OLDPWD");
	old_pwd_val = old_pwd ? strtok(old_pwd, "=") : curr_dir;

	/* Set the target directory to the previous working directory */
	dir = old_pwd_val;

	/* Print the target directory to the standard output */
	write(STDOUT_FILENO, dir, _strlen(dir));
	write(STDOUT_FILENO, "\n", 1);

	/* Update the environment variables 'PWD' and 'OLDPWD' */
	_setenv("PWD", dir, 1);
	_setenv("OLDPWD", curr_dir, 1);

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

char *cd_to(char *path, char *curr_dir)
{
	char *dir = path;

	/* Set the current working directory to the specified path */
	_setenv("PWD", path, 1);

	/* Update the environment variable 'OLDPWD' */
	_setenv("OLDPWD", curr_dir, 1);

	return  (dir);
}
