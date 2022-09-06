#ifndef _HANDLE_ENV_H
#define _HANDLE_ENV_H

#include "root.h"
#include "string_t.h"

/**
 * print_list - _print linked list
 * @h: linked list
 * Return: size of linked list
 */
__home size_t print_list(list_t *h)
{
	list_t *temp_list = h;
	int count = 0;
	int c = 0;

	if (!h)
		return (0);
	while (temp_list)
	{
		if (!temp_list->c)
			write(STDOUT, "(nil)\n", 6);
		else
		{
			c = 0;
			while ((temp_list->c)[c])
			c++;
			write(STDOUT, temp_list->c, c);
			write(STDOUT, "\n", 1);
		}
		temp_list = temp_list->next;
		count++;
	}
	return (count);
}

/**
 * add_node_end - add node to end of linked list
 * @head: pointer to head of linked list
 * @str: data to new node
 * Return: pointer to new_list linked list
 */
__home list_t *add_node_end(list_t **head, __silent char *str)
{
	list_t *new_list = NULL;
		list_t *temp = NULL;

	new_list = malloc(sizeof(list_t));
	if (!new_list)
		return (NULL);

	(*new_list).c = _strdup(str);
	(*new_list).next = NULL;

	if (!(*head))
	{
		*head = new_list;
		goto KILL;
	}

	temp = *head;
	while ((*temp).next)
		temp = (*temp).next;
	(*temp).next = new_list;

KILL:	return (new_list);
}

/**
 * free_list - frees linked list
 * @list: linked list
 */
__home void free_list(list_t *list)
{
	list_t *temp = NULL;

	while (list)
	{
		temp = list;
		list = list->next;
		free(temp->c);
		free(temp);
	}
}

/**
 * env_list - create linked list of env
 * @env: enviroment variable
 * Return: list_t
 */
__home list_t *env_list(char **env)
{
	list_t *head = NULL;
	int i = 0;

	for (i = 0; env[i]; i++)
		add_node_end(&head, env[i]);
	return (head);
}
#endif
