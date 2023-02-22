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

/**
 * deli_count - Counts delimiters in a string
 * @s: The string that contains the delimiters
 * @deli: The delimiters to will find in the string
 *
 * Return: The number of delimiters in the string
 */

int deli_count(char *s, char *deli)
{
	int i = 0, j = 0, cw = 0;

	while (deli[i])
	{
		j = 0;
		while (s[j])
		{
			if (s[j] == deli[i])
				cw++;
			j++;
		}
		i++;
	}

	return (cw);
}
