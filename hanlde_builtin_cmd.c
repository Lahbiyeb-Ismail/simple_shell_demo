#include "shell.h"

/**
 * handle_builtin_cmd - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @status: pointer to the exit status of the previous command.
 * @cmd_idx: The index of the command in the shell's command history.
 *
 * Return: The updated exit status after executing the built-in command.
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
		/* Check if the command is the "setenv" or "unsetenv" built-in command */
	else if (_strcmp(cmd[0], "setenv") == 0 || _strcmp(cmd[0], "unsetenv") == 0)
	{
		/* Check if the required number of arguments is provided */
		if ((!cmd[1] || (_strcmp(cmd[0], "setenv") == 0)) && !cmd[2])
		{
			print_env_error(cmd, &exit_status, argv[0], cmd_idx);
			return (exit_status);
		}

		if (_strcmp(cmd[0], "setenv") == 0)
			exit_status = _setenv(cmd[1], cmd[2], 1);
		else if (_strcmp(cmd[0], "unsetenv") == 0)
			exit_status = _unsetenv(cmd[1]);

		free_memory(cmd);
	}

	return (exit_status);
}

