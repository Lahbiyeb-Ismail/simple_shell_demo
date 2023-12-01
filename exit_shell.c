#include "shell.h"

/**
 * exit_shell - Exit the shell
 *
 * Description: This function frees the memory allocated for the command
 * and exits the shell with the provided exit status.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @exit_status: The exit status to be used when exiting the shell.
 *
 * Return: void
 */

void exit_shell(char **cmd, int *exit_status)
{
	/* Free memory allocated for the command */
	free_memory(cmd);

	/* Exit the shell with the provided exit status  */
	exit(*exit_status);
}
