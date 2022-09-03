#ifndef _EXIT_H
#define _EXIT_H

/**
 * __exit - temporary exit
 * @str: str
 */
__home void __exit(char *str)
{
	if (!_strcmp(str, "exit"))
		exit(0);
}

#endif
