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
 * @argv: The array of dynamically allocated tokens to be freed.
 *
 * Return: void
 *
*/

void free_memory(char **argv)
{
	size_t i;

	if (!argv)
		return;

	/* Iterate through the array of tokens and free each individual token */
	for (i = 0; argv[i]; i++)
		free(argv[i]), argv[i] = NULL;

	/* Free the array of tokens */
	free(argv), argv = NULL;
}
