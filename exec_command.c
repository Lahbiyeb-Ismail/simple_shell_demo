#include "shell.h"

/**
 * exec_command - Execute the command with its arguments
 *
 * Description: This function creates a child process to execute
 * the command specified by the array of tokens using execve.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: An array of strings representing the command-line arguments.
 * @cmd_idx: Index of the command in the token array.
 * @exit_status: Index of the command in the token array.
 *
 * Return: 0 on success, -1 on failure.
 *
*/

int exec_command(char **cmd, char **argv, int cmd_idx, int *exit_status)
{
	pid_t pid;
	char *cmd_path = NULL;

	cmd_path = get_cmd_path(cmd, argv, cmd_idx);

	if (!cmd_path)
		return (127);

	pid = fork();

	if (pid < 0)
		return (-1);

	if (pid == 0)
		child_process_exec(cmd_path, cmd);
	else
		parent_process_exec(pid, cmd, cmd_path, exit_status);

	return (WEXITSTATUS(*exit_status));
}


/**
 * get_cmd_path - Get the full path of a command and handle errors
 *
 * Description: This function retrieves the full path of a command using
 * the  _getpath function.
 * If the command path is not found, it prints a shell error message
 * using print_shell_error, frees the memory allocated for the command,
 * and returns NULL.
 * Otherwise, it returns the full path of the command.
 *
 * @cmd: Array of tokens representing the command and its arguments.
 * @argv: Array of tokens representing the arguments passed to the shell.
 * @cmd_idx: The index of the command in the token array.
 *
 * Return: A pointer to the full path of the command if found, NULL otherwise.
 */

char *get_cmd_path(char **cmd, char **argv, int cmd_idx)
{
	char *cmd_path = NULL;
	char *err_msg = "not found";

	/* Get the full path of the command */
	cmd_path = _getpath(cmd[0]);

	/* If the command path is not found, print an error message and return NULL */
	if (!cmd_path)
	{
		print_shell_error(argv[0], cmd_idx, cmd, err_msg);
		return (NULL);
	}

	/* Return the full path of the command */
	return (cmd_path);
}

/**
 * child_process_exec - Execute a command in a child process
 *
 * Description: This function executes a command in a child process using
 * the execve system call. If the execve call fails, it frees the memory
 * allocated for the command path and the command itself before returning.
 *
 * @cmd_path: The full path of the command to be executed.
 * @cmd: Array of tokens representing the command and its arguments.
 *
 * Return: void
 */

void child_process_exec(char *cmd_path, char **cmd)
{
	int ret_val;

	/* Execute the command using execve */
	ret_val = execve(cmd_path, cmd, environ);

	/* If execve fails, free memory and return */
	if (ret_val == -1)
	{
		free(cmd_path), cmd_path = NULL;
		free_memory(cmd);
	}
}

/**
 * parent_process_exec - Handle execution in the parent process after forking
 *
 * Description: This function waits for the child process with the
 * specified PID to finish, collects its exit status, and then frees the
 * memory allocated for the command and its path.
 *
 * @pid: The process ID of the child process.
 * @cmd: Array of tokens representing the command and its arguments.
 * @cmd_path: The full path of the command.
 * @exit_status: The exit status of the child process.
 *
 * Return: void
 */

void parent_process_exec(pid_t pid, char **cmd, char *cmd_path,
	int *exit_status)
{
	/* Wait for the child process to finish and collect its exit status */
	waitpid(pid, exit_status, 0);

	/* Free memory allocated for the command and its path */
	free_memory(cmd);
	free(cmd_path), cmd_path = NULL;
}
