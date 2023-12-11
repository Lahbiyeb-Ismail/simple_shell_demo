#include "shell.h"

/**
 * handle_var_replacement - Handles variable replacement in a command.
 *
 * Description:
 * This function takes a command represented as an array of strings (`cmd`) and
 * the exit status of the previous command (`exit_status`). It checks for
 * variable patterns like "$?", "$$", or environment variables in the command
 * and replaces them accordingly.
 *
 * The function uses the check_if_builtin_cmd function to determine if the
 * command is a built-in command. If it is, it calls handle_builtin_cmd to
 * execute the built-in command and updates the exit status. If it is not
 * a built-in command, the function calls exec_command to execute the external
 * command and updates the exit status.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @exit_status: The exit status of the previous command.
 *
 */

void handle_var_replacement(char **cmd, int exit_status)
{
	char *env_key = NULL;
	char *env_val = NULL;
	char *temp = NULL;

	pid_t pid = getpid();

	/* Check if the command is "echo" and the second argument starts with '$' */
	if (_strcmp(cmd[0], "echo") == 0 && cmd[1][0] == '$' && cmd[1][1])
	{
		/* Replace "$?" with the exit status */
		if (cmd[1][1] == '?')
		{
			temp = _itoa(exit_status);
			free(cmd[1]);
			cmd[1] = temp;
		}
		/* Replace "$$" with the process ID */
		else if (cmd[1][1] == '$')
		{
			temp = _itoa(pid);
			free(cmd[1]);
			cmd[1] = temp;
		}
	/* Replace environment variables with their values */
		else
		{
			env_key = strtok(cmd[1], "$");
			env_val = _getenv(env_key);
			free(cmd[1]);
			cmd[1] = env_val;
		}
	}
}
