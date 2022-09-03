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
 */
__home void ctrl_d(ssize_t ret)
{
	if (ret == -1)
	{
		write(STDOUT, "^D\n", 3);
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
	char *s, *text, *delim = " \n";
	size_t len;
	int i;
	char temp_s[1024];
	char **arg = NULL;
	ssize_t ret = 0;

	s = NULL;
	arg = malloc(sizeof(char));
	ret = getline(&s, &len, stdin);
	ctrl_d(ret);
	for (text = strtok(s, delim), i = 0 ; text; i++)
	{
		arg[i] = malloc(sizeof(char) * (_strlen(text) + 20));
		if (!arg[i])
			return (NULL);
		if (!i && access(text, F_OK))
		{
			__exit(text);
			sprintf(temp_s, "%s", get_path(env_l, text));
			if (!access(temp_s, F_OK))
				_strcpy(arg[i], temp_s);
			else
				_strcpy(arg[i], text);
			/*temp_s = get_path(env_l, text);
			arg[i] = malloc(sizeof(char) * (_strlen(temp_s) + 1));
                	if (!arg[i])
                        	return (NULL);
			_strcpy(arg[i], temp_s);*/
			goto NEXT;
		}
		/*arg[i] = malloc(sizeof(char) * (_strlen(text) + 6));
                if (!arg[i])
                        return (NULL);*/
		_strcpy(arg[i], text);

NEXT:		
		text = strtok(NULL, delim);
	}
	arg[i] = text;
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
	pid_t pid;
	list_t *env_l;

	env_l = env_list(env);

RESET:
	if (__interactive)
		start_i();

	else
		non_int = TRUE;

	signal(SIGINT, ctrl_c);
	arg = split_prompt(env_l);
	if (!arg[0])
		goto RESET;
	else
		pid = fork();

	if (pid == 0)
	{
		if (execve(arg[0], arg, env) == -1)
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
