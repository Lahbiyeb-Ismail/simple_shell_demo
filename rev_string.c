#include "shell.h"

/**
 * rev_string - Entry point
 *
 *  * @str: pointer to a string
 *  * @strlen: string length
 *
 * Description: Function that reverses a string.
 *
 * Return: void
 *
 */

void rev_string(char *str, int strlen)
{
	int start = 0;
	int end = strlen - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
