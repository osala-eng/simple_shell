#include "root.h"

/**
 * _cd - Change directory
 *
 * @arguments: arguments
 *
 * Return : 1
 */

int _cd(char **arguments)
{
	char cwd[1024];
	int index;
	int cwd_size = 0;

	if (!arguments[1] || (arguments[1][0] == '~' && !arguments[1][1]))
		chdir(hsh_getenv("HOME"));

	else if (arguments[1][0] == '-' && !arguments[1][1])
	{
		chdir(hsh_getenv("OLDPWD"));
		getcwd(cwd, sizeof(cwd));
		for (index = 0; cwd[index] != '\0'; index++)
			cwd_size++;

		cwd[index] = '\n';
		write(1, cwd, cwd_size + 1);
	}

	else if (access(arguments[1], F_OK) == 0)
	{
		if (access(arguments[1], R_OK) != 0)
			return (-1);
		else

			chdir(arguments[1]);
	}

	else

		return (-1);

	return (1);
}
