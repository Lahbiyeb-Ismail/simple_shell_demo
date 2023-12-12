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
 * @aliases: A pointer to the head of the linked list containing the aliases.
 *
 * Return: The updated exit status after executing the built-in command.
 */

int handle_builtin_cmd(char **cmd, char **argv, int *status, int cmd_idx,
	Alias **aliases)
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
		exit_status = handle_env(cmd, argv, cmd_idx);
	else if (_strcmp(cmd[0], "cd") == 0)
		exit_status = handle_cd(cmd, argv, cmd_idx);
	else if (_strcmp(cmd[0], "alias") == 0)
	{
		exit_status = handle_alias_command(cmd, aliases);
		free_memory(cmd);
	}

	return (exit_status);
}

/**
 * handle_env - Handle environment-related commands: setenv and unsetenv.
 *
 * Description: This function processes environment-related commands,
 * such as setenv and unsetenv, updating the environment variables accordingly.
 * It checks if the correct number of arguments is provided for each command
 * and calls the corresponding function (_setenv or _unsetenv) to perform
 * the desired action.
 * If an incorrect number of arguments is provided, it prints an error message.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @cmd_idx: The index of the command in the shell's command history.
 *
 * Return: The exit status after handling the environment command.
 */

int handle_env(char **cmd, char **argv, int cmd_idx)
{
	int exit_status;

	int cmd_len = 0;

	while (cmd[cmd_len] != NULL)
		cmd_len++;

	if (cmd_len < 2 || (cmd_len < 3 && _strcmp(cmd[0], "setenv") == 0))
	{
		exit_status = print_env_error(cmd, argv[0], cmd_idx);
		return (exit_status);
	}
	if (_strcmp(cmd[0], "setenv") == 0)
		exit_status = _setenv(cmd[1], cmd[2], 1);
	else if (_strcmp(cmd[0], "unsetenv") == 0)
		exit_status = _unsetenv(cmd[1]);

	free_memory(cmd);
	return (exit_status);
}


/**
 * handle_cd -  Handles the execution of the 'cd' command in the shell.
 *
 * Description: This function calls the change_dir function to perform the
 * actual directory change based on the provided 'cmd' array, which is expected
 * to contain the 'cd' command and its arguments. The function also frees
 * memory allocated for the 'cmd' array after the directory change operation.
 *
 * @cmd: Array of strings representing the 'cd' command and its arguments.
 * @argv: Array of strings representing the cmd_line arguments of the shell.
 * @cmd_idx: Index of the 'cd' command in the 'argv' array.
 *
 * Return: An integer representing the exit status of the 'cd' command.
 * 0: Success
 * 2: Error (failed to change directory)
 */

int handle_cd(char **cmd, char **argv, int cmd_idx)
{
	int exit_status = 0;

	exit_status = change_dir(cmd);

	if (exit_status == -1)
	{
		print_shell_error(argv[0], cmd_idx, cmd, "can't cd to ");
		return (2);
	}

	free_memory(cmd);
	return (exit_status);
}
