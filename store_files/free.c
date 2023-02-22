#include "shell.h"

/**
 * frees_getsenv - Function that frees the enviontment variable
 * @envipath: The environment variable to be freed
 *
 * Return: Nothing
 */
void frees_getsenv(char *envipath)
{
	int i;

	for (i = 4; i >= 0; i--)
		envipath--;

	free(envipath);
}

/**
 * frees_tkn - Function that frees the token
 * @tkn: Token to be freed
 *
 * Return: Nothing
 */
void frees_tkn(char **tkn)
{
	char **temp = tkn;

	if (tkn)
	{
		while (*tkn)
			free(*tkn++);

		free(temp);
	}
}
