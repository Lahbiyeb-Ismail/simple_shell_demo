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
	/* Array to store the tokens */
	char **cmd = NULL;
	/* Counter for the number of tokens */
	size_t count = 0;
	size_t i = 0;

	if (!cmd_line)
		return (NULL);
	/* Create a copy of the command for tokenization */
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
	/* Check if the memory allocation failed */
	if (!cmd)
	{
		free(cmd_line), cmd_line = NULL;
		return (NULL);
	}
	/* Reset token to the start of the copied command */
	token = strtok(cmd_line, delim);
	/* Fill the 'argv' array with token strings*/
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	/* Set the last element of the tokens array to Null*/

	free(cmd_line), cmd_line = NULL;
	cmd[i] = NULL;
	return (cmd);
}
