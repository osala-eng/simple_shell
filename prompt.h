#ifndef _PROMPT_F_H
#define _PROMPT_F_H

#include "root.h"

/**
 * ctrl_c - ignore ctrl-c and reprompt
 * @n: takes int from signal
 */
__home__ void ctrl_c(int n)
{
	(void) n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * prompt - prompt
 * @env: env
 *
 * Return: int
 */
__home__ int prompt(__silent char **env)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	return (0);
}
#endif
