#include "shell.h"


/**
 * check_for_operator - Check if the command line contains a specific operator.
 *
 * Description:
 * This function scans the given command line and checks if it contains a
 * specific operator, such as a semicolon (';'). If the operator is found, a
 * pointer to the operator is returned; otherwise, NULL is returned.
 *
 * @cmd_line: The command line to be checked for the operator.
 *
 * Return:
 * Returns a pointer to the operator if found, or NULL if the operator is not
 * present in the command line.
 */

char *check_for_operator(char *cmd_line)
{
	int i;

	for (i = 0; cmd_line[i]; i++)
	{
		if (cmd_line[i] == ';')
		{
			free(cmd_line);
			return (";");
		}
		else if (cmd_line[i] == '&' && cmd_line[i + 1] == '&')
		{
			free(cmd_line);
			return ("&&");
		}
		else if (cmd_line[i] == '|' && cmd_line[i + 1] == '|')
		{
			free(cmd_line);
			return ("||");
		}
	}

	free(cmd_line);
	return (NULL);
}
