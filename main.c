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
	* @argc: The number of command-line arguments.
	* @argv: An array of strings representing the command-line arguments.
	*
	* Return: 0 in success execution
	*
	*/

int main(int argc, char **argv)
{
	/* Buffer to store the user's input cmd */
	char *cmd_line = NULL;
	/* Array to store the tokens of the cmd */
	char **cmd = NULL;
	int exit_status = 0, cmd_idx = 0, is_comment = 0;
	FILE *file = NULL;

		/* If a filename is provided as an argument, open the file */
	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		if (!file)
		{
			print_file_error(argv[0], cmd_idx, argv[1]);
			exit(2);
		}
	}

	do {
		cmd_line = read_and_handle_comments(&is_comment, file, argc);

		if (!cmd_line)
		{
			handle_exit(is_comment, &exit_status);
			continue;
		}

		cmd_idx++;

		handle_command_exec(cmd, cmd_line, argv, cmd_idx, &exit_status);
	} while (1);

	 /* Close the file if it was opened */
	if (file)
		fclose(file);

	free_memory(cmd);
	return (0);
}


/**
 * read_and_handle_comments - Read the command and handle comments.
 *
 * Description: This function prompts the user and reads the command,
 * then checks and handles comments if present.
 *
 * @is_comment: Pointer to the comment flag.
 * @file: The file to read from.
 * @argc: The number of command-line arguments.
 *
 *
 * Return: Pointer to the command line.
 */

char *read_and_handle_comments(int *is_comment, FILE *file, int argc)
{
	char *cmd_line = NULL;

	if (file)
			/* If a file is provided, read from the file instead of stdin */
		cmd_line = read_command(file, argc);
	else
		cmd_line = read_command(stdin, argc);

	*is_comment = check_for_comments(cmd_line);

	if (*is_comment == 1)
		cmd_line = handle_comments(cmd_line);

	return (cmd_line);
}


/**
 * handle_exit -  Handle the exit conditions and exit the shell if necessary.
 *
 * Description: If the command line is not available and it's not a comment,
 * this function prints a new line before exiting, but only if in
 * interactive mode.
 *
 * @is_comment: Flag indicating if the command line is a comment.
 * @exit_status: Pointer to the exit status variable.
 *
 * Return: void
 */

void handle_exit(int is_comment, int *exit_status)
{
	if (!is_comment)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(*exit_status);
	}
}


/**
 * handle_command_exec -  Handle the execution of a command.
 *
 * Description: This function checks for the presence of an operator in
 * the command line.
 * If an operator is found, it delegates the handling to the appropriate
 * function. Otherwise, it tokenize the command and processes it.
 *
 * @cmd: The array of tokens representing the command.
 * @cmd_line: The command line to process.
 * @argv: An array of strings representing the command-line arguments.
 * @cmd_idx: The index of the command.
 * @exit_status: Pointer to the exit status variable.
 *
 * Return: void
 */

void handle_command_exec(char **cmd, char *cmd_line, char **argv,
	int cmd_idx, int *exit_status)
{
	char *operator = NULL;

	operator = check_for_operator(cmd_line);

	if (operator)
		handle_operators(argv, cmd_line,
			operator, exit_status, cmd_idx);
	else
	{
		cmd = tokenize_command(cmd_line, " \t\n");
		if (!cmd)
			return;
		process_command(cmd, argv, cmd_idx, exit_status);
	}
}
