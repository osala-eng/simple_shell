#include "prompt.h"

/**
 * main - creates a simple shell
 * @ac: num of args
 * @av: argument vectors
 * @env: environmental variables
 * Return: 0
 */
int main(__silent int ac, __silent char **av, __silent char **env)
{
	int ret;

	ret = prompt(av, env);
	return (ret);
}
