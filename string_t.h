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

/**
 * print - custom print
 * @format: string
 * Returrn: always 0
 */
__home int print(const char * const format, ...)
{
	va_list params;
	int i;
	char *temp;

	va_start(params, format);

	for (i = 0; format && format[i]; i++)
	{
		temp = va_arg(params, char *);
		write(STDOUT, temp, _strlen(temp));
	}
	va_end(params);
	return (0);
}
#endif
