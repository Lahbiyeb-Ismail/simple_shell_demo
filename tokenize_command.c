#include "shell.h"

void if_error_exit(char **argv);

/**
 * tokenize_command - Tokenize a command string into an array of tokens.
 *
 * Description: This function takes a command string and tokenize it
 * using space and newline characters as delimiters.
 * It returns an array of tokens and updates the provided argument 'argc'
 * with the number of tokens.
 *
 * @cmd: The command string to tokenize.
 * @argc: Pointer to a size_t variable to store the number of tokens.
 *
 * Return: An array of dynamically allocated strings representing tokens.
 *
*/

char **tokenize_command(char *cmd, size_t *argc)
{
	/* Create a copy of the command for tokenization */
	char *cmd_cpy = strdup(cmd);
	/* Tokenize the original command */
	char *token = strtok(cmd, " \n");
	/* Array to store the tokens */
	char **argv = NULL;
	/* Counter for the number of tokens */
	size_t count = 0;
	size_t i = 0;

	/* Count the number of tokens int the original command */
	while (token)
	{
		token = strtok(NULL, " \n");
		count++;
	}

	/* Update the provided 'argc' with the token count */
	*argc = count;
	/* Allocate memory for the array of tokens */
	argv = malloc(sizeof(char *) * count);
	/* Check if the memory allocation failed */
	if_error_exit(argv);

		/* Reset token to the start of the copied command */
	token = strtok(cmd_cpy, " \n");

	/* Fill the 'argv' array with token strings*/
	for (; i < count; i++)
	{
		argv[i] = strdup(token);
		/* Check if the memory allocation failed */
		if (!argv[i])
		{
			perror("Failed to allocate memory");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \n");
	}

	/* Set the last element of the tokens array to Null*/
	argv[count] = NULL, free(cmd_cpy);
	return (argv);
}

/**
 * if_error_exit - Helper function
 *
 * Description: This function check the memory is allocated correctly
 *
 * @argv: Array to store the tokens of the cmd
 *
 * Return: void
 *
*/

void if_error_exit(char **argv)
{
	if (!argv)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
}
