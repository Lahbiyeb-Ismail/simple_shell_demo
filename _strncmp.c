#include "shell.h"

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @num: number of bytes
 * Return: the result of the comparison
 */

int _strncmp(char *s1, char *s2, int num)
{
	int i, j, max;
	char *s3;

	if (_strlen(s1) <= _strlen(s2))
	{
		max = _strlen(s1);
		s3 = s1;
	}
	else
	{
		max = _strlen(s2);
		s3 = s2;
	}
	for (i = 0; i < num && i <= max && s3[i] != '\0'; i++)
	{
		j = s1[i] - s2[i];

		if (j != 0)
			break;
	}

	if (i == num)
		return (0);
	return (j);
}
