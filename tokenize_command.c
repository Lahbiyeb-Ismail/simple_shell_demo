#include "shell.h"

/**
 * tokenize_command - Tokenize a command string into an array of tokens.
 *
 * Description: This function takes a command string and tokenize it
 * using space and newline characters as delimiters.
 * It returns an array of tokens and updates the provided argument 'argc'
 * with the number of tokens.
 *
 * @cmd_line: The command string to tokenize.
 *
 * Return: An array of dynamically allocated strings representing tokens.
 *
*/

char **tokenize_command(char *cmd_line)
{
	char *cmd_cpy = NULL, *token = NULL, *delim = " \t\n";
	char **cmd = NULL;
	size_t count = 0, i = 0;

	if (!cmd_line)
		return (NULL);
	cmd_cpy = _strdup(cmd_line);
	/* Tokenize the command copy*/
	token = strtok(cmd_cpy, delim);
	if (!token)
	{
		free(cmd_line), cmd_line = NULL;
		free(cmd_cpy), cmd_cpy = NULL;
		return (NULL);
	}
	/* Count the number of tokens int the original command */
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(cmd_cpy), cmd_cpy = NULL;
	/* Allocate memory for the array of tokens */
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(cmd_line), cmd_line = NULL;
		return (NULL);
	}
	token = strtok(cmd_line, delim);
	/* Fill the 'argv' array with token strings*/
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	free(cmd_line), cmd_line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
