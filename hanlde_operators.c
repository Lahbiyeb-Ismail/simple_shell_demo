#include "shell.h"

/**
 * handle_operators - Execute commands separated by operators (';', '&&', '||')
 *
 * Description:
 * This function takes a command line, splits it into multiple commands using
 * the specified operator, and processes each command using the process_command
 * function. The behavior depends on the type of operator:
 *
 * - For '&&' (logical AND): Executes each command sequentially. If a command
 *   fails (returns a non-zero exit status), subsequent commands are skipped.
 *
 * - For '||' (logical OR): Executes each command sequentially. If a command
 *   succeeds (returns a zero exit status), subsequent commands are skipped.
 *
 * - For ';' (sequential command execution): Executes each command sequentially
 *   without considering the exit status of previous commands.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @cmd_line: The entire command line string.
 * @operator: The operator used to separate commands (';', '&&', '||').
 * @exit_status: Pointer to the exit status variable, which is updated by
 * the function.
 * @cmd_idx: Index of the command in the token array.
 *
 */

void handle_operators(char **cmd, char **argv,
	char *cmd_line, char *operator, int *exit_status, int cmd_idx)
{
	char **multi_cmd = NULL;
	int i;
	int status = (*exit_status);

	multi_cmd = tokenize_command(cmd_line, operator);

	for (i = 0; multi_cmd[i]; i++)
	{
			/* Tokenize (split) the command and get the array of tokens */
		cmd = tokenize_command(multi_cmd[i], " \t\n");

		if (!cmd)
			continue;

		process_command(cmd, argv, cmd_idx, &status);

		if (_strcmp(operator, "&&") == 0)
			if (status != 0)
				break;

		if (_strcmp(operator, "||") == 0)
			if (status == 0)
				break;
	}
}
