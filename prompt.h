#ifndef _PROMPT_F_H
#define _PROMPT_F_H

#include "root.h"
#include "handle_env.h"

/**
 * temp_exit - temporary exit
 * @str: str
 */
__home void temp_exit(char *str)
{
	if (!_strcmp(str, "exit"))
		exit(0);
}

/**
 * ctrl_c - ignore ctrl-c and reprompt
 * @i: int
 */
__home void ctrl_c(int __silent i)
{
	write(STDOUT_FILENO, "\n", 1);
	start_i();
}

/**
 * ctrl_d - exit if control d
 * @ret: getline status
 */
__home void ctrl_d(ssize_t ret)
{
	if (ret == -1)
	{
		write(STDOUT_FILENO, "^D\n", 3);
		exit(0);
	}
}

/**
 * split_prompt - part of prompt func
 * Return: aray of args
 */
__home char **split_prompt(void)
{
	char *s, *text, *delim = " \n";
	size_t len;
	int i;
	char temp_s[100];
	char **arg = NULL;
	ssize_t ret = 0;

	s = NULL;
	arg = malloc(sizeof(char));
	ret = getline(&s, &len, stdin);
	ctrl_d(ret);
	for (text = strtok(s, delim), i = 0 ; text; i++)
	{
		arg[i] = malloc(sizeof(char) * (_strlen(text) + 6));
		if (!arg[i])
			return (NULL);
		if (!i && access(text, F_OK))
		{
			temp_exit(text);
			sprintf(temp_s, "/bin/%s", text);
			strcpy(arg[i], temp_s);
			goto NEXT;
		}
		strcpy(arg[i], text);
NEXT:		text = strtok(NULL, delim);
	}
	arg[i] = text;

	free(s);
	free(text);
	return (arg);
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
	int status = 0;
	int non_int = 0;
	char **arg;

	__silent pid_t pid;

RESET:
	if (__interactive)
		start_i();

	else
		non_int = 1;

	signal(SIGINT, ctrl_c);
	arg = split_prompt();
	if (!arg[0])
		goto RESET;
	else
		pid = fork();

	if (pid == 0)
	{
		if (execve(arg[0], arg, env) == -1)
			printf("%s: 1: %s: not found\n", av[0], arg[0]);
	}
	else
		wait(&status);

	free_array(arg);
	if (!non_int)
		goto RESET;

	return (0);
}
#endif
