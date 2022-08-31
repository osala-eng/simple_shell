#ifndef _STR_TOOLS_A_H
#define _STR_TOOLS_A_H

#include "root.h"

/**
 * _strlen - len of str
 * @s: string
 * Return: len of str
 */
__home__ int _strlen(char *s)
{
	if (!*s)
		return (0);

	s++;
	return (1 + _strlen(s));
}

/**
 * _strcat - concatenate two strings
 * @dest: string 1
 * @src: string 2
 * Return: concatenated string
 */
__home__ char *_strcat(char *dest, char *src)
{
	int len, len2, total_len, j;

	for (len = 0; dest[len]; len++)
		total_len++;

	for (len2 = 0; src[len2]; len2++)
		total_len++;

	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	for (j = 0; src[j]; j++, len++)
		dest[len] = src[j];

	dest[len] = END;

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if match
 */
__home__ int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; *(s1 + i) == *(s2 + i) && *(s1 + i);)
		i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}

/**
 * _strcpy - copies the string pointed to by src,
 * @dest: string
 * @src: string
 * Return: new str loc
 */
__home__ char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len];)
		len++;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strdup - duplicate string
 * @str: string to duplicate
 * Return: pointer to duplicated string
 */
__home__ char *_strdup(char *str)
{
	char *new_str;
	int i, len;

	if (!str)
		return (NULL);

	for (len = 0; *(str + len);)
		len++;

	new_str = malloc(sizeof(char) * ++len);
	if (!new_str)
		return (NULL);

	for (i = 0; i < len; i++)
		*(new_str + i) = *(str + i);

	return (new_str);
}
#endif
