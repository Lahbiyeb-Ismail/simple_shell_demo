#include "shell.h"

/**
 * main - Entry Point
 *
 * Description: This function serves as the entry point for the program.
 * It prompts the
 * user to enter a command, reads the command, tokenize it into an array
 * of tokens, and then performs any additional processing required.
 * Finally, it frees the allocated memory before exiting.
 *
 * Return: 0 in success execution
 *
*/

int main(void)
{
	/* Buffer to store the user's input cmd */
	char *cmd = NULL;
	/* Array to store the tokens of the cmd */
	char **argv = NULL;
	/* Number of tokens in the command */
	size_t argc;
	int i = 0;

	printf("$ ");

	/* Prompt user and read the command */
	cmd = read_command();

	/* Tokenize (split) the command and get the array of tokens */
	argv = tokenize_command(cmd, &argc);

	while (argv[i])
		printf("%s\n", argv[i++]);

	/* Free the allocated memory */
	free_memory(cmd, argv);

	return (0);
}
