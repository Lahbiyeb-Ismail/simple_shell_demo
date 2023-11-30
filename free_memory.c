#include "shell.h"

/**
 * free_memory - Frees the memory allocated for the command and its tokens.
 *
 * Description: This function takes a command string and an array of
 * tokens, both dynamically allocated, and frees the memory associated
 * with them. It iterates through the array of tokens and frees each
 * individual token before freeing the array itself. Finally, it frees
 * the memory used for the original command string.
 *
 * @cmd: The dynamically allocated command string to be freed.
 * @argv: The array of dynamically allocated tokens to be freed.
 *
 * Return: void
 *
*/

void free_memory(char *cmd, char **argv)
{
	size_t i = 0;

	/* Iterate through the array of tokens and free each individual token */
	for (; argv[i]; i++)
		free(argv[i]);

	/* Free the array of tokens */
	free(argv);
	/* Free the original command string */
	free(cmd);
}
