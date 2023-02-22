#include "shell.h"

/**
 * removeLine - Removes a new line character from string
 * @s: string
 *
 * Return:String without a new line character
 */
char *removeLine(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}

	return (s);
}
