#include "shell.h"

/**
 * word_count - Counts the words typed
 * @s: string containing the words
 *
 * Return: The number of words present in the string
 */
int word_count(char *s)
{
	int i = 0, j = 0, k = 0;

	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			k = 0;
		else if (k == 0)
		{
			k = 1;
			j++;
		}

		i++;
	}

	return (j);
}
