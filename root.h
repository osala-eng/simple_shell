#ifndef _ROOT_H
#define _ROOT_H

/*
 * Define macros
 */

#define __silent __attribute__((unused))
#define __interactive isatty(STDIN_FILENO)
#define __home __attribute__((weak)) 
#define END '\0'
#define TEMP_PATH "/bin"

#define BLUE (write(STDOUT_FILENO, "\033[0;34m", 8))
#define NC (write(STDOUT_FILENO, "\033[0m", 5))
#define GREEN (write"\033[0;32m"

/*
 * Includes
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>


/**
 * struct list - linked list
 * @c: string
 * @next: next node
 */
typedef struct list
{
        char *c;
        struct list *next;
} list_t;

/*
int prompt(char **av, char **env);
list_t *add_node_end(list_t **head, char *str);
void free_list(list_t *list);
int print_env(char **str, list_t *env);
list_t *env_list(char **env);
size_t print_list(list_t *h);
*/
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int len);
int _strcmp(char *s1, char *s2);
char *_strconcat(char *s1, char *s2);
char *_strdup(char *str);

/**
 * start_i - begining of prompt
 */
__home void start_i(void)
{
	BLUE;
	write(STDOUT_FILENO, "simple_shell", 12);
	NC;
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * free_array - free array
 * @str: array of strings
 */
__home void free_array(char **str)
{
	int i;

	for (i = 0; str[i]; i++)
		free(str[i]);
	free(str);
}
#endif
