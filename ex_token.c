#include "shell.h"

/**
 * tokenize - Extract token from string
 * @str: The string to tokenize
 * @del: The delimiter of tokenization
 * @len: amount of tokens
 *
 * Return: An array of tokens of the string
 */
char **tokenize(char *str, char *del, int len)
{
	char **token = NULL, *tkn = NULL, *temp = NULL;
	int i = 0;

	token = malloc(sizeof(char *) * (len + 1));
	if (!token)
		return (NULL);

	str = removeLine(str);
	temp = _strdup(str);
	tkn = strtok(temp, del);

	while (tkn)
	{
		token[i] = _strdup(tkn);
		tkn = strtok(NULL, del);
		i++;
	}

	token[i] = NULL;
	free(temp);
	return (token);
}
