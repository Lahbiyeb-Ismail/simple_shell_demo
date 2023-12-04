#include "shell.h"

/**
 * _getpath - Get the full path of a command
 *
 * Description: This function attempts to find the full path of a command by
 * checking the directories listed in the PATH environment variable. If the
 * command contains a slash ("/"), it checks whether it's an absolute or
 * relative path and returns a duplicate of the command if it exists. If the
 * command doesn't contain a slash, it searches for the command in each
 * directory listed in the PATH variable.
 *
 * @cmd: The command for which to find the full path.
 *
 * Return: A pointer to the full path of the command if found, NULL otherwise.
 */

char *_getpath(char *cmd)
{
	char *path_val, *dir_path, *cmd_path;
	char *delim = ":";
	unsigned int dir_path_len = 0, cmd_len = 0, i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));

			return (NULL);
		}
	}
	path_val = _getenv("PATH");
	if (!path_val)
		return (NULL);
	dir_path = strtok(path_val, delim);
	while (dir_path)
	{
		dir_path_len = _strlen(dir_path);
		cmd_len = _strlen(cmd);
		cmd_path = malloc(dir_path_len + cmd_len + 2);
		if (cmd_path)
		{
			_strcpy(cmd_path, dir_path);
			_strcat(cmd_path, "/");
			_strcat(cmd_path, cmd);
			if (stat(cmd_path, &st) == 0)
			{
				free(path_val);
				return (cmd_path);
			}
			free(cmd_path), cmd_path = NULL;
			dir_path = strtok(NULL, delim);
		}
	}
	free(path_val);
	return (NULL);
}

/**
 * check_command - Get the full path of a command
 *
 * Description: This function attempts to find the full path of a command by
 * checking the directories listed in the PATH environment variable. If the
 * command contains a slash ("/"), it checks whether it's an absolute or
 * relative path and returns a duplicate of the command if it exists. If the
 * command doesn't contain a slash, it searches for the command in each
 * directory listed in the PATH variable.
 *
 * @cmd: The command for which to find the full path.
 * @st: The command for which to find the full path.
 *
 * Return: A pointer to the full path of the command if found, NULL otherwise.
 */

char *check_command(char *cmd, struct stat st)
{
	size_t i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));

			return (NULL);
		}
	}

	return (NULL);
}
