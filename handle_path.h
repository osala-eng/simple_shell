#ifndef HANDLE_PATH_H
#define HANDLE_PATH_H

#include "string_t.h"
#include "getline_def.h"

/**
 * copy_env - copy value from env without key
 * @str: value from env with key
 * @look_i: key len
 * Return: value w/o key
 */
__home char *copy_env(char *str, int look_i)
{
	char *_str = NULL;
	int i = 0, len = 0;

	if (!str)
		return (NULL);

	len = _strlen(str) + 1;

	_str = malloc(sizeof(char) * (len - look_i));
	if (!_str)
		return (NULL);

	for (i = 0; i < (len - look_i); i++)
		*(_str + i) = *(str + look_i + i);

	return (_str);
}

/**
 * env_lookup - look up a given value from env
 * @str: value to look
 * @env: env list
 * Return: Variable from env
 */
__home char *env_lookup(char *str, list_t *env)
{
	int i = 0, look_i = 0;

	for (; env;)
	{
		for (i = 0; (env->c)[i] == str[i];)
			i++;
		if (!str[i] && (env->c)[i] == '=')
			break;
		env = env->next;
	}

	for (look_i = 0; str[look_i];)
		look_i++;

	return (copy_env(env->c, ++look_i));
}

/**
 * get_path - look for commandfile from path
 * @env: env
 * @key: key
 * Return: command path or command on failure
 */
__home char *get_path(list_t *env, char *key)
{
	char *path = NULL;
	char *paths[1024];
	char *buffer = NULL;
	int i = 0, j = 0;
	char temp_s[1024];

	if (!access(key, F_OK))
		return (key);

	path = env_lookup("PATH", env);
	if (!path)
		return (key);

	for (buffer = __str_tok(path, ":"), i = 0; buffer; i++)
	{
		paths[i] = buffer;
		buffer = __str_tok(NULL, ":");
	}
	paths[i] = NULL;
	free(path);

	for (i = 0; paths[i]; i++)
	{
		sprintf(temp_s, "%s/%s", paths[i], key);
		if (!access(temp_s, F_OK))
		{
			for (j = 0; temp_s[j]; j++)
				key[j] = temp_s[j];
			return (key);
		}
	}

	return (key);
}
#endif
