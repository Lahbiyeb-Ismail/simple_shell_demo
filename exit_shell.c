#include "shell.h"

/**
 * exit_shell - Exit the shell
 *
 * Description: This function frees the memory allocated for the command
 * and exits the shell with the provided exit status.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @exit_status: The exit status of the previous command.
 * @cmd_idx: Index of the command in the token array.
 *
 * Return: The exit status value.
 */

int exit_shell(char **cmd, char **argv, int *exit_status, int cmd_idx, char **new_env)
{
	int exit_val = (*exit_status);
	char *err_msg = "Illegal number";

	if (cmd[1])
	{
		if (is_positive_num(cmd[1]))
			exit_val = _atoi(cmd[1]);
		else
		{
			print_shell_error(argv[0], cmd_idx, cmd, err_msg);
			exit_val = 2;

			return (exit_val);
		}
	}

	/* Free memory allocated for the command*/
	free_memory(cmd);
	free(*new_env);

	/* Exit the shell with the provided exit status  */
	exit(exit_val);
}
