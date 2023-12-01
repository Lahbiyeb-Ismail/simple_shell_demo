#include "shell.h"

/**
 * _getpath - Execute the command with its arguments
 *
 * Description: This function creates a child process to execute
 * the command specified by the array of tokens using execve.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 *
 * Return: A pointer to the full path of the command if found, NULL
 * otherwise.
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

