#include "root.h"

/**
 * _strlen - len of str
 * @s: string
 *
 * Return: len of str
 */

int _strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * hsh_strncmp - Compare two strings with a specific length
 * @s1: String 1
 * @s2: String 2
 * @len: Length
 *
 * Return: Difference of characters (0 - Equal)
 */
int hsh_strncmp(char *s1, char *s2, int len)
{
	int i = 1;

	while (i <= len)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
