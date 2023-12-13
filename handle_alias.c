#include "shell.h"

/**
 * handle_alias_command -  Handles the execution of an 'alias'
 * command in the shell.
 *
 * Description:  This function processes the 'alias' command, which is
 * used to define, display, or print aliases in the shell.
 * If no arguments are given, it prints all existing aliases.
 * If arguments are provided, it interprets them to define or display a
 * specific alias. The format for defining an alias is
 * "alias_name=alias_value".
 * If only the alias_name is provided, it prints the corresponding alias.
 * If an alias with the given name is not found, an error message is displayed.
 * If the alias_value contains spaces, they should be passed as separate
 * arguments in cmd. The function updates the aliases linked list accordingly,
 * either by printing, setting, or displaying aliases.
 *
 * @cmd: An array of strings representing the command and its arguments.
 * @aliases: A pointer to the head of the linked list containing the aliases.
 *
 * Return: 0 on success, 1 on failure.
 *
*/

int handle_alias_command(char **cmd, Alias **aliases)
{
	if (!cmd[1])
		/* If no arguments are given, print all aliases */
		print_aliases(*aliases);
	else
	{
		int i;
		char *alias_name = strtok(cmd[1], "=");
		char *alias_val = strtok(NULL, "\n");

		for (i = 2; cmd[i]; i++)
		{
			_strcat(alias_val, " ");
			_strcat(alias_val, cmd[i]);
		}

		if (!alias_val)
		{
				/* If no value is given, print the alias */
			Alias *alias = find_alias(*aliases, alias_name);

			if (alias)
				print_aliases(alias);
			else
			{
				char *err_msg = " not found";

				write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
				write(STDERR_FILENO, ": ", 2);
				write(STDERR_FILENO, alias_name, _strlen(alias_name));
				write(STDERR_FILENO, err_msg, _strlen(err_msg));
				write(STDERR_FILENO, "\n", 1);
				return (1);
			}
		}
		else
			set_alias(aliases, alias_name, alias_val);
	}

	return (0);
}

/**
 * print_aliases - Prints the aliases stored in a linked list.
 *
 * Description: This function traverses the linked list of aliases and
 * prints each alias in the format "alias_name=alias_value" to the standard
 * output (stdout). It iterates through the list, printing each alias on a
 * new line. The function assumes that each alias node in the list has 'name'
 * and 'value' members representing the alias name and its corresponding value.
 *
 * @aliases: A pointer to the head of the linked list containing the aliases.
 *
 * Return: void
 */

void print_aliases(Alias *aliases)
{
	Alias *current = aliases;

	while (current)
	{
		write(STDOUT_FILENO, current->name, _strlen(current->name));
		write(STDOUT_FILENO, "=", 1);
		write(STDOUT_FILENO, "'", 1);
		write(STDOUT_FILENO, current->value, _strlen(current->value));
		write(STDOUT_FILENO, "'", 1);
		write(STDOUT_FILENO, "\n", 1);
		current = current->next;
	}
}

/**
 * print_aliases - Finds an alias with a specified name in a linked
 * list of aliases.
 *
 * Description: This function iterates through a linked list of aliases,
 * comparing the 'name' attribute of each alias with the specified 'name'.
 * If a matching alias is found, a pointer to that Alias node is returned.
 * If no match is found, the function returns NULL. The function assumes a
 * specific structure for the Alias nodes in the linked list, with 'name'
 * and 'value' members representing the alias name and its corresponding value.
 *
 * @aliases: A pointer to the head of the linked list containing the aliases.
 * @name: The name of the alias to be found.
 *
 * Return: A pointer to the Alias node with the specified name,
 * or NULL if not found.
 */

Alias *find_alias(Alias *aliases, char *name)
{
	Alias *current = aliases;

	while (current)
	{
		if (_strcmp(current->name, name) == 0)
			return (current);

		current = current->next;
	}
	return (NULL);
}

/**
 * set_alias - Sets or updates an alias in a linked list of aliases.
 *
 * Description:
 * This function first checks if an alias with the specified 'name' already
 * exists in the linked list.
 * If an alias with the same name is found, its value is updated with the
 * provided 'value'. If no matching alias is found, a new alias is created
 * and added to the front of the linked list with the specified 'name'
 * and 'value'. The function handles memory allocation for the new alias and
 * ensures proper freeing of memory for existing alias values. The function
 * assumes a specific structure for the Alias nodes in the linked list,
 * with 'name' and 'value' members representing the alias name and its
 * corresponding value.
 *
 * @aliases: A pointer to the head of the linked list containing the aliases.
 * @name: The name of the alias to be set or updated.
 * @value: The value to be associated with the alias.
 *
 * Return: void
 */

void set_alias(Alias **aliases, char *name, char *value)
{
	Alias *alias = find_alias(*aliases, name);

	if (alias)
	{
			/* If the alias already exists, update its value */
		char *new_value = _strdup(value);

		if (!new_value)
		{
			perror("Error: Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		free(alias->value);
		alias->value = new_value;
	}
	else
	{
		/* Otherwise, create a new alias and add it to the list */
		alias = malloc(sizeof(Alias));
		if (!alias)
		{
			perror("Error: Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		alias->name = _strdup(name);
		alias->value = _strdup(value);

		if (!alias->name || !alias->value)
		{
			perror("Error: Memory allocation failed");
			free(alias->name);
			free(alias->value);
			free(alias);
			exit(EXIT_FAILURE);
		}
		alias->next = *aliases;
		*aliases = alias;
	}
}

/**
 * free_aliases - Frees the memory allocated for a linked list of aliases.
 *
 * Description:
 * This function iterates through a linked list of aliases, freeing the memory
 * allocated for each alias node. It also frees the memory allocated for the
 * 'name' and 'value' attributes of each alias. The function ensures proper
 * deallocation of memory and prevents memory leaks associated with the linked
 * list of aliases. The function assumes a specific structure for the Alias
 * nodes in the linked list, with 'name' and 'value' members representing the
 * alias name and its corresponding value.
 *
 * @aliases: A pointer to the head of the linked list containing the aliases.
 *
 * Return: void
 */

void free_aliases(Alias *aliases)
{
	Alias *current = aliases;
	Alias *next = NULL;

	while (current != NULL)
	{
		next = current->next;

		free(current->name);
		free(current->value);
		free(current);
		current = next;
	}
}
