#ifndef _BUILT_IN_H
#define _BUILT_IN_H

#include "string_t.h"
#include "exit.h"

/**
 * struct func - struct
 * @key: key
 * @meth: function
 */
typedef struct func
{
	char *key;
	int (*meth)(list_t*, char**);
} func_p;

/**
 * env_built_in - handle command env
 * @env_l: env list
 * @str: string array
 * Return: 0
 */
__home int env_built_in(list_t *env_l, __silent char **str)
{
	print_list(env_l);
	free_array(str);
	return (EOF);
}

/**
 * get_meth - look for built in method
 * @str: key
 * Return: function
 */
__home
int (*get_meth(char *str))(list_t*, char**)
{

	func_p ops[] = {
		{"env", env_built_in},
		{"exit", exit_built_in},
		/*
		 * {"setenv", setenv_built_in},
		 * {"unsetenv", unsetenv_built_in},
		 * {"alias", alias_built_in},
		 * {"cd", cd_built_in}
		 */
		{NULL, NULL} };
	int i = 0;

	for (i = 0; ops[i].key; i++)
	{
		if (!_strcmp(str, ops[i].key))
			return (ops[i].meth);
	}

	return (NULL);
}

/**
 * built_in - handle built in functions
 * @env_l: env
 * @str: key
 * Return: int
 */
__home int built_in(list_t *env_l, char **str)
{
	int (*meth)(list_t*, char**);
	int ret = 0;

	meth = get_meth(str[0]);
	if (!meth)
		return (0);
	ret = meth(env_l, str);

	return (ret);
}
#endif
