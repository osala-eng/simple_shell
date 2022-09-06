#ifndef _PROMPT_F_H
#define _PROMPT_F_H

#include "handle_env.h"
#include "handle_path.h"
#include "built_in.h"
#include "getline_def.h"

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
 * @ret: __get_line status
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
	ret = __get_line(&s, &len, stdin);
	ctrl_d(ret, s, arg, env_l);
	for (text = __str_tok(s, delim), i = 0 ; text; i++)
	{
		arg[i] = malloc(sizeof(char) * (_strlen(text) + 1));
		if (!arg[i])
			return (arg);
		_strcpy(arg[i], (char *)text);
		text = __str_tok(NULL, delim);
	}
	arg[i] = NULL;
	/*free(s);*/
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
	pid_t pid = 0;
	list_t *env_l = NULL;
	char *path = NULL;
	int bi_ret = 0;

	env_l = env_list(env);
RESET:
	if (__interactive)
		start_i();
	else
		non_int = TRUE;
	signal(SIGINT, ctrl_c);
	arg = split_prompt(env_l);
	path = get_path(env_l, arg[0]);
	pid = 0;
	bi_ret = 0;
	bi_ret = built_in(env_l, arg);
	if (!arg[0] || bi_ret == EOF)
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
	if (!non_int)
		goto RESET;
	return (0);
}
#endif
