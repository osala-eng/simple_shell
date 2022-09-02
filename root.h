#ifndef _ROOT_H
#define _ROOT_H

/*
 * Define macros
 */

#define __silent __attribute__((unused))
#define __interactive isatty(STDIN_FILENO)
#define __home inline
#define END '\0'

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

int prompt(char **av, char **env);
void start_i(void);

#endif /* _ROOT_H */
#ifndef _ROOT_FUNCS
#define _ROOT_FUNCS

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
#endif
