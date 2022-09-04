#ifndef _STR_TOOLS_B_H
#define _STR_TOOLS_B_H

#include "strtools.h"

/**
 * _strcpy - copy string
 * @dest: destination
 * @src: source
 *
 * Return: Character
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = _strlen(src);
	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
#endif
