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
	char *cmd_line = NULL;
	/* Array to store the tokens of the cmd */
	/*char **argv = NULL;*/
	/* Number of tokens in the command */
	/*size_t argc;*/

	int exit_status = 0;

	do {
		/* Prompt user and read the command */
		cmd_line = read_command();

		if (!cmd_line)
		{
			/* Print a new line befor exit if we are in the interactive mode */
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);

			return (exit_status);
		}

		free(cmd_line);


		/* Tokenize (split) the command and get the array of tokens */
		/*argv = tokenize_command(cmd_line, &argc);*/

		/* Execute the command and get the exit status */
		/*exit_status = exec_command(argv);*/

	} while (1);


	/* Free the allocated memory */
	/*free_memory(cmd_line, argv);*/

	return (exit_status);
}
