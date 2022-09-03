#ifndef _ROOT_H
#define _ROOT_H

/*
 * Define macros
 */

#define __silent __attribute__((unused))
#define __interactive isatty(STDIN)
#define __home __attribute__((weak))
#define END '\0'
#define TEMP_PATH "/bin"

#define BLUE (write(STDOUT, "\033[0;34m", 8))
#define NC (write(STDOUT, "\033[0m", 5))
#define GREEN (write(STDOUT, "\033[0;32m", 8))

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
#include <stdarg.h>

/**
 * enum simple_bool - simple boolean
 * @FALSE: NO
 * @TRUE: YES
 * @STDIN: IN
 * @STDOUT: OUT
 */
enum simple_bool
{
	FALSE,
	TRUE,
	STDIN = STDIN_FILENO,
	STDOUT = STDOUT_FILENO
};

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

typedef unsigned int uint;
typedef unsigned long int ulint;

/**
 * start_i - begining of prompt
 */
__home void start_i(void)
{
	BLUE;
	write(STDOUT, "simple_shell", 12);
	NC;
	write(STDOUT, "$ ", 2);
}

/**
 * free_array - free array
 * @str: array of strings
 */
__home void free_array(char **str)
{
	int i;

	if (!str && !*str)
		return;

	for (i = 0; str[i]; i++)
		free(str[i]);
	free(str);
}
#endif
