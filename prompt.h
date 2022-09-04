#ifndef _PROMPT_F_H
#define _PROMPT_F_H

#include "handle_env.h"
#include "handle_path.h"
#include "exit.h"

/**
 * ctrl_c - ignore ctrl-c and reprompt
 * @i: int
 */
__home void ctrl_c(int __silent i)
{
	write(STDOUT, "\n", 1);
	start_i();
}

/**
 * ctrl_d - exit if control d
 * @ret: getline status
 * @s: string to free
 * @arg: tokens to free
 * @env_l: list to free
 */
__home void ctrl_d(ssize_t ret, char *s, char **arg, list_t *env_l)
{
	if (ret == EOF)
	{
		write(STDOUT, "^D\n", 3);
		free(arg);
		free(s);
		free_list(env_l);
		exit(0);
	}
}

/**
 * split_prompt - part of prompt func
 * @env_l: env
 * Return: aray of args
 */
__home char **split_prompt(__silent list_t *env_l)
{
	char *s = NULL;
	char *text = NULL;
	char *delim = " \n";
	size_t len = 0;
	int i = 0;
	char **arg = NULL;
	ssize_t ret = 0;

	arg = malloc(sizeof(char));
	ret = getline(&s, &len, stdin);
	ctrl_d(ret, s, arg, env_l);
	for (text = strtok(s, delim), i = 0 ; text; i++)
	{
		arg[i] = malloc(sizeof(char) * (_strlen(text) + 1));
		if (!arg[i])
			return (arg);
		_strcpy(arg[i], (char *)text);
		text = strtok(NULL, delim);
	}
	arg[i] = NULL;
	free(s);
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
	char **arg = NULL;
	pid_t pid;
	list_t *env_l = NULL;
	char *path = NULL;

	env_l = env_list(env);

RESET:
	if (__interactive)
		start_i();

	else
		non_int = TRUE;
	signal(SIGINT, ctrl_c);
	arg = split_prompt(env_l);
	path = get_path(env_l, arg[0]);
	__exit(path);
	pid = 0;
	if (!arg[0])
		goto RESET;
	else if (!access(path, F_OK))
		pid = fork();

	if (pid == 0)
	{
		if (execve(path, arg, env) == EOF)
			printf("%s : 1: %s: not found\n", av[0], arg[0]);
	}
	else
		wait(&status);

	if (arg[0])
		free_array(arg);
	/*free(path);*/
	if (!non_int)
		goto RESET;

	return (0);
}
#endif
