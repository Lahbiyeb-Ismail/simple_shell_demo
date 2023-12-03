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
	char *cmd_cpy, *token = NULL, *delim = " \t\n";
	char **cmd = NULL;
	size_t count = 0;

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

	/* Count the number of tokens in a string */
	count = tokens_count(token, delim);

	free(cmd_cpy), cmd_cpy = NULL;

	/* Create an array of tokens from a string */
	cmd = tokens_array(count, cmd_line, delim, token);

	return (cmd);
}


/**
 * tokens_count - Count the number of tokens in a string
 *
 * Description: This function counts the number of tokens in a string
 * by using the strtok function with a specified delimiter. It iterates
 * through the string until no more tokens are found and returns the
 * count of tokens.
 *
 * @token: The string to be tokenized.
 * @delim: The delimiter used for tokenization.
 *
 * Return: The number of tokens in the string.
 */

size_t tokens_count(char *token, char *delim)
{
	size_t count = 0;

	/* Count the number of tokens in the original command */
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}

	return (count);
}


/**
 * tokens_array - Create an array of tokens from a string
 *
 * Description: This function takes a string and tokenize it using a specified
 * delimiter. It then allocates memory for an array of strings, copying each
 * token into the array. The last element of the array is set to NULL.
 *
 * @count: The number of tokens in the string.
 * @cmd_line: The original command line string.
 * @delim: The delimiter used for tokenization.
 * @token: A temporary string pointer used in the tokenization process.
 *
 * Return: A dynamically allocated array of strings (tokens)
 * or NULL on failure.
 */

char **tokens_array(size_t count, char *cmd_line, char *delim, char *token)
{
	size_t i = 0;
	char **cmd = NULL;

	/* Allocate memory for the array of tokens */
	cmd = malloc(sizeof(char *) * (count + 1));
	if (!cmd)
	{
		free(cmd_line), cmd_line = NULL;
		return (NULL);
	}

	/* Tokenize the cmd_line string */
	token = strtok(cmd_line, delim);

	/* Fill the 'cmd' array with token strings */
	while (token)
	{
		cmd[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}

	/* Free the original command line string */
	free(cmd_line), cmd_line = NULL;

	/* Set the last element of the array to NULL */
	cmd[i] = NULL;

	return (cmd);
}
