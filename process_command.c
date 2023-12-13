#include "shell.h"

/**
 * process_command - Process a command by executing it and updating
 * the exit status
 *
 * Description:
 * This function takes an array of command tokens, checks if it is a built-in
 * command, and either executes the command using exec_command or a built-in
 * command handler, updating the exit status accordingly.
 *
 * The function uses the check_if_builtin_cmd function to determine if the
 * command is a built-in command. If it is, it calls handle_builtin_cmd to
 * execute the built-in command and updates the exit status. If it is not
 * a built-in command, the function calls exec_command to execute the external
 * command and updates the exit status.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @cmd_idx: Index of the command in the token array.
 * @exit_status: Pointer to the exit status variable, which is updated by
 * the function.
 * @aliases: A pointer to the head of the linked list containing the aliases.
 * @new_env: Pointer to the environment variable (can be updated during
 * command execution).
 *
 */

void process_command(char **cmd, char **argv, int cmd_idx, int *exit_status,
	Alias **aliases, char **new_env)
{
	int status = (*exit_status);

	/* Handle variable replacement in the command */
	handle_var_replacement(cmd, status);

	/* Check if the command is a built-in command */
	if (check_if_builtin_cmd(cmd[0]))
		(*exit_status) = handle_builtin_cmd(cmd, argv, &status, cmd_idx,
			aliases, new_env);
	else
	/* Execute the command and get the exit status */
		(*exit_status) = exec_command(cmd, argv, cmd_idx, &status);
}
