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
	char *home_env = NULL, *home_val = NULL;
	char *old_pwd = NULL, *old_pwd_val = NULL;


	home_env = _getenv("HOME");
	old_pwd = _getenv("OLDPWD");

	home_val = home_val ? strtok(home_env, "=") : NULL;
	old_pwd_val = old_pwd ? strtok(old_pwd, "=") : NULL;

	if (!cmd[1] && home_val)
		dir = home_val;
	else if (_strcmp(cmd[1], "-") == 0)
	{
		dir = old_pwd_val;
	}
	else
		dir = cmd[1];

	status = chdir(dir);

	return (status);
}
