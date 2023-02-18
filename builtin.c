#include "shell.h"

/**
 * execbuilt - Executes built-in commands
 * @tkn: token
 * @line: line
 *
 * Return: 1 if success and 0 if not
 */

int execbuilt(char **tkn, char *line)
{
	int i = 0;
	char *bulitincommands[] = {"env"}

	while (builtincommands[i])
	{
		if (_strcmp(tkn[0], builtincommands[i]) == 0)
		{
			switch (i)
			{
				case 0:
					print_env();
					return (1);
				default:
					break;
			}
		}
		i++;
	}

	return (0);
}
