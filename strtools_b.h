#ifndef STR_TOOLS_B_H
#define STR_TOOLS_B_H

#include "root.h"

/**
 * t_strlen - returns token's string length for mallocing
 * @str: string
 * @pos: index
 * @delim: delimeter
 * Return: token length
 */
__home__ int t_strlen(char *str, int pos, char delim)
{
	int len;

	for (len = 0; str[pos] != delim && str[pos]; len++)
		pos++;

	return (len);
}

/**
 * t_size - returns number of delim ignoring continuous delim
 * @str: string
 * @delim: delimeter
 * Return: number of delims
 */
__home__ int t_size(char *str, char delim)
{
	int i, num_delim;

	for (i = 0, num_delim = 0; str[i]; i++)
	{
		if (str[i] == delim && str[i + 1] != delim)
			num_delim++;

		if (str[i] == delim && !str[i + 1])
			num_delim--;
		i++;
	}
	return (num_delim);
}

/**
 * ignore_delim - returns a string without preceeding delims
 * @str: string
 * @delim: delimiter
 * Return: new string
 */
__home__ char *ignore_delim(char *str, char delim)
{
	while (*str == delim)
		str++;
	return (str);
}

/**
 * _str_tok - tokenizes a string and returns an array of tokens
 * @str: string
 * @delim: delimeter
 * Return: an array of tokens
 */
__home__ char **_str_tok(char *str, char *delim)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delim[0];
	str = ignore_delim(str, d_ch);
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (!toks)
		return (NULL);

	while (str[se])
		se++;

	while (si < se)
	{
		if (str[si] != d_ch)
		{
			len = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (!toks[p])
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != END))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = END;
			t++;
		}

		if (si < se && (str[si + 1] != d_ch && str[si + 1] != END))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL;
	return (toks);
}

/**
 * _realloc - allocate memory and set all values to 0
 * @ptr: pointer
 * @old_size: int
 * @new_size: int
 * Return: pointer to reallocated memory
 */
__home__ void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (!ptr)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		else
			return (p);
	}

	p = malloc(new_size);
	if (!p)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr);

	return (p);
}
#endif
