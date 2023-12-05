#include "shell.h"

/**
 * handle_builtin_cmd - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @status: The exit status of the previous command.
 * @cmd_idx: Index of the command in the token array.
 *
 * Return: void
 */

int handle_builtin_cmd(char **cmd, char **argv, int *status, int cmd_idx)
{
	int exit_status = (*status);

	/* Check if the command is the "exit" built-in command */
	if (_strcmp(cmd[0], "exit") == 0)
		exit_status = exit_shell(cmd, argv, status, cmd_idx);
	/* Check if the command is the "env" built-in command */
	else if (_strcmp(cmd[0], "env") == 0)
		exit_status = print_env(cmd);
		/* Check if the command is the "setenv" built-in command */
	else if (_strcmp(cmd[0], "setenv") == 0)
	{
		char *env_err_msg = "Unable to add/remove from environment";

		if (!cmd[1] || !cmd[2] || _setenv(cmd[1], cmd[2], 1) == -1)
		{
			print_shell_error(argv[0], cmd_idx, cmd, env_err_msg);
			exit_status = -1;
			return (exit_status);
		}

		exit_status = _setenv(cmd[1], cmd[2], 1);
		free_memory(cmd);
	}
	/* Check if the command is the "unsetenv" built-in command */
	else if (_strcmp(cmd[0], "unsetenv") == 0)
	{
		char *env_err_msg = "Unable to add/remove from environment";

		if (!cmd[1] || !cmd[2] || _unsetenv(cmd[1]) == -1)
		{
			print_shell_error(argv[0], cmd_idx, cmd, env_err_msg);
			exit_status = -1;
			return (exit_status);
		}

		exit_status = _unsetenv(cmd[1]);
		free_memory(cmd);
	}
	return (exit_status);
}
