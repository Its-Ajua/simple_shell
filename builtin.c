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
	char *builtincommands[] = { "exit", "cd", "help", "env", NULL };

	while (builtincommands[i])
	{
		if (_strcmp(tkn[0], builtincommands[i]) == 0)
		{
			switch (i)
			{
				case 0:
					handle_exit(tkn, line);
				case 1:
					cdir(tkn[1]);
					return (1);
				case 2:
					open_help();
					return (1);
				case 3:
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
