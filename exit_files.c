#include "shell.h"

/**
 * handle_exit - exits a file
 * @tkn: token
 * @line: line
 *
 * Return: Nothing
 */
void handle_exit(char **tkn, char *line)
{
	int status = 0;

	if (tkn[1] == NULL || (!_strcmp(tkn[1], "0")))
	{
		frees_tkn(tkn);
		free(line);
		exit(0);
	}
	status = _atoi(tkn[1]);
	if (status != 0)
	{
		frees_tkn(tkn);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(tkn[1]);
		_puts("\n");
		exit(2);
	}

	frees_tkn(tkn);
	free(line);
	exit(EXIT_SUCCESS);
}

