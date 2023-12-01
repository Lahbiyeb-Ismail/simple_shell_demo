#include "shell.h"

/**
 * _atoi - Entry point
 *
 *  * @s: pointer to a string
 *
 * Description: Function that convert a string to an integer.
 *
 * Prototype: int _atoi(char *s);
 *
 * Return: string converted to an integer
 *
 */

int _atoi(char *s)
{

	int i;
	int sign = 1;
	unsigned int num = 0;
	int digit_encounter = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit_encounter = 1;
			num = num * 10 + (s[i] - '0');
		}

		else if (digit_encounter)
			break;

	}

	if (sign < 0)
		num = -num;

	return (num);
}

