#include "shell.h"

/**
 * handle_builtin_cmd - Handle execution of built-in commands
 *
 * Description: This function checks if the given command is a built-in
 * command and executes the corresponding action.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @exit_status: The exit status of the previous command.
 *
 * Return: void
 */

void handle_builtin_cmd(char **cmd, int exit_status)
{
	/* Check if the command is the "exit" built-in command */
	if (_strcmp(cmd[0], "exit") == 0)
		exit_shell(cmd, exit_status);
}
