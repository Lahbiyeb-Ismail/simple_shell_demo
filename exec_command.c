#include "shell.h"

/**
 * exec_command - Execute the command with its arguments
 *
 * Description: This function creates a child process to execute
 * the command specified by the array of tokens using execve.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @env: An array of strings representing the environment variables.
 *
 * Return: 0 on success, -1 on failure.
 *
*/

int exec_command(char **cmd, char **argv, char **env)
{
	pid_t pid;
	int ret_val;
	int status;

	pid = fork();

	if (pid < 0)
		return (-1);

 /* Child process */
	if (pid == 0)
	{
		ret_val = execve(cmd[0], cmd, env);

		if (ret_val == -1)
		{
			perror(argv[0]);
			free_memory(cmd);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_memory(cmd);
	}

	return (WEXITSTATUS(status));
}
