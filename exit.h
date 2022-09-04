#ifndef _EXIT_H
#define _EXIT_H

#include "string_t.h"

/**
 * exit_built_in - temporary exit
 * @str: str
 * @env_l: list
 * Return: 0
 */
__home int exit_built_in(list_t *env_l, char **str)
{
	int status = 0;

	if (str[1])
		status = cint(str[1]);

	free_array(str);
	free_list(env_l);
	exit(status);
	return (0);
}

#endif
