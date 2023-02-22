#include "shell.h"

/**
 * handle_exit - handling exits
 * @tkn: token
 * @line: line
 *
 * Return: Nothing
 */
void handle_exit(char **tokn, char *line)
{
	int status = 0;

	if (tokn[1] == NULL || (!_strcmp(tokn[1], "0")))
	{
		frees_tkn(tokn);
		free(line);
		exit(0);
	}
	status = _atoi(tokn[1]);
	if (status != 0)
	{
		frees_tkn(tokn);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(tokn[1]);
		_puts("\n");
		exit(2);
	}

	frees_tkn(tokn);
	free(line);
	exit(EXIT_SUCCESS);
}
