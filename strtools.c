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
 * _strncmp - Compare two strings with a specific length
 * @s1: String 1
 * @s2: String 2
 * @len: Length
 *
 * Return: Difference of characters (0 - Equal)
 */
int _strncmp(char *s1, char *s2, int len)
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

/**
 * _strcmp - Compare two strings
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Difference of characters (0 - Equal)
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * _strconcat - Copies a string and returns a pointer to the array.
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Pointer to the array or NULL.
 */

char *_strconcat(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0, n = 0;
