#include "shell.h"

/**
 * print_shell_prompt - Print the shell prompt.
 *
 * Description: This function is responsible for displaying the shell prompt,
 * which typically consists of the '$' character followed by a space.
 * It writes the prompt to the standard output (STDOUT_FILENO).
 */

void print_shell_prompt(void)
{
	/* If we are in the interactive mode print "$ "*/
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
