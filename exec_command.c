#include "shell.h"

/**
 * exec_command - Execute the command with its arguments
 *
 * Description: This function creates a child process to execute
 * the command specified by the array of tokens using execve.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @cmd_idx: Index of the command in the token array.
 *
 * Return: 0 on success, -1 on failure.
 *
*/

int exec_command(char **cmd, char **argv, int cmd_idx)
{
	pid_t pid;
	int ret_val;
	int status;
	char *cmd_path = NULL;
	char *err_msg = "not found";

	cmd_path = _getpath(cmd[0]);
	if (!cmd_path)
	{
		print_shell_error(argv[0], cmd_idx, cmd, err_msg);
		free_memory(cmd);
		return (127);
	}

	pid = fork();

	if (pid < 0)
		return (-1);

	if (pid == 0)
	{
		ret_val = execve(cmd_path, cmd, environ);

		if (ret_val == -1)
		{
			free(cmd_path), cmd_path = NULL;
			free_memory(cmd);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_memory(cmd);
		free(cmd_path), cmd_path = NULL;
	}

	return (WEXITSTATUS(status));
}
