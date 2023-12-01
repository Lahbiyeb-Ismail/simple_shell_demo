#include "shell.h"

/**
 * _itoa - Convert an integer to a string
 *
 * Description: This function converts an integer to its equivalent
 * string representation and returns a pointer to the resulting string.
 *
 * @num: The integer to convert.
 *
 * Return: A pointer to the string representation of the integer.
 *
 */

char *_itoa(int num)
{
	char str[20];
	int i = 0;

	if (num == 0)
		str[i++] = '0';
	else
	{
		while (num > 0)
		{
			str[i++] = (num % 10) + '0';
			num = num / 10;
		}
	}

	str[i] = '\0';
	rev_string(str, i);

	return (_strdup(str));
}
