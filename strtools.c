#include "root.h"

/**
 * hsh_strlen - len of str
 * @s: string
 *
 * Return: len of str
 */

int hsh_strlen(char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}
