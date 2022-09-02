#ifndef _PROMPT_F_H
#define _PROMPT_F_H

#include "root.h"

/**
 * ctrl_c - ignore ctrl-c and reprompt
 * @n: takes int from signal
 */
__home void ctrl_c(void)
{
	start_i();
}

/**
 * prompt - prompt
 * @env: env
 * @av: variable array
 *
 * Return: int
 */
__home int prompt(char **av, char **env)
{
	char *s;
	size_t len;
	__silent ssize_t ret;
	char *delim = " \n", *text, *arg[1024];
	int i, status = 0;
	int non_int = 0;
	__silent pid_t pid;

RESET:	if (__interactive)
		start_i();
	else
		non_int = 1;
	
	s = NULL;
	ret = 0;

	ret = getline(&s, &len, stdin);
	
	for (text = strtok(s, delim), i = 0 ; text; i++)
	{
		arg[i] = text;
		text = strtok(NULL, delim);
	}
	arg[i] = NULL;
	
	if (!arg[0])
		goto RESET;

	pid = fork();
	
	if (pid == 0)
	{
		if (execve(arg[0], arg, env) == -1)
			printf("%s: 1: %s: not found\n", av[0], arg[0]);
	}
	else
		wait(&status);

	if (!non_int)
		goto RESET;

	return (0);
}
#endif
