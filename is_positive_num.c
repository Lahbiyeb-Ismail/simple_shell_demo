#include "shell.h"

/**
 * is_positive_num - Check if a string represents a positive number
 *
 * Description: This function checks if a given string represents a positive
 * number by examining each character in the string. It returns 1 if the string
 * is a positive number, and 0 otherwise. If the input string is NULL, the
 * function returns 0.
 *
 * @str: The string to check.
 *
 * Return: 1 if the string is a positive number, 0 otherwise.
 */

int is_positive_num(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}
