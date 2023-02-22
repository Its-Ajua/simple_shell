#include "shell.h"

/**
 * handle_exit - exits a file
 * @tkn: token
 * @line: line to be checked
 *
 * Return: Nothing
 */
void handle_exit(char **tkn, char *line)
{
	int status = 0;

	if (tkn[1] == NULL || (!_strcmp(tkn[1], "0")))
	{
		free_tkn(tkn);
		free(line);
		exit(0);
	}
	status = _atoi(tkn[1]);
	if (status != 0)
	{
		free_tkn(tkn);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit: Unidentified number: ");
		_puts(tkn[1]);
		_puts("\n");
		exit(2);
	}

	free_tkn(tkn);
	free(line);
	exit(EXIT_SUCCESS);
}

