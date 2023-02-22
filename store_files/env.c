#include "shell.h"

/**
 * _getsenv - Gets the environment variable
 * @var: variable to find in the environment
 *
 * Return: environment variable
 */
char *_getsenv(const char *var)
{
	int i = 0;
	char *envi = NULL;

	while (environ[i])
	{
		if (_strncmp(var, environ[i], _strlen(var)) == 0)
		{
			envi = _strdup(environ[i]);
			while (*envi != '=')
				envi++;
			++envi;
			return (envi);
		}
		i++;
	}

	return (NULL);
}
