#include "shell.h"

/**
 * exec_command - Execute the command with its arguments
 *
 * Description: This function creates a child process to execute
 * the command specified by the array of tokens using execve.
 *
 * @argv: Array of tokens representing the command and its arguments.
 *
 * Return: 0 on success, -1 on failure.
 *
*/

int exec_command(char **argv)
{
	pid_t pid;
	int ret_val;

	pid = fork();

	if (pid < 0)
		return (-1);

	if (pid == 0)
	{
		ret_val = execve(argv[0], argv, NULL);

		if (ret_val == -1)
		{
			perror("Error in execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
	}

	return (0);
}
