#ifndef _ALIAS_H
#define _ALIAS_H

#include "string_t.h"

__home char *alias(char *arg, list_t *alias_l)
{
	if (_strcmp(arg[0], "alias"))
		return (NULL);

	if (!arg[1])
		print_list(alias_l);
}

#endif
