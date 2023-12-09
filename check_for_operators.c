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
	char *and_operator = "&&";
	char *or_operator = "||";
	char *consecutive_operator = ";";

	for (i = 0; cmd_line[i]; i++)
	{
		if (cmd_line[i] == consecutive_operator[0])
			return (consecutive_operator);
		else if (cmd_line[i] == and_operator[0] &&
			cmd_line[i + 1] == and_operator[1])
			return (and_operator);
		else if (cmd_line[i] == or_operator[0] && cmd_line[i + 1] == or_operator[1])
			return (or_operator);
	}

	return (NULL);
}
