#include "shell.h"

/**
 * concat - Concatenate a path name and a program name
 * @path: The path name to concatenate with the program name
 * @name: The program name to place in the path name
 *
 * Return: The path name concatenated with the program name
 */
char *concat(char *path, char *name)
{
	int name_len = 0, path_len = 0, size = 0;

	name_len = _strlen(name);
	path_len = _strlen(path);
	size = sizeof(char) * (path_len + name_len + 2);
	path = _realloc(path, (path_len + 1), size);
	if (!path)
		return (NULL);

	_strcat(path, "/");
	_strcat(path, name);

	return (path);
}

/**
 * find - Verify if a command is found in the system
 * @comname: The command name to find in the system
 *
 * Return: The path name of the command found or NULL if failed
 */
char *find(char *comname)
{
	char *env_path = NULL, **p_tokns = NULL;
	int i = 0, num_del = 0;
	struct stat sh;

	if (comname)
	{
		if (stat(comname, &sh) != 0 && comname[0] != '/')
		{
			env_path = _getsenv("PATH");
			num_del = deli_count(env_path, ":") + 1;
			p_tokns = tokenize(env_path, ":", num_del);

			while (p_tokns[i])
			{
				p_tokns[i] = concat(p_tokns[i], comname);

				if (stat(p_tokns[i], &sh) == 0)
				{
					free(comname);
					comname = _strdup(p_tokns[i]);
					frees_getsenv(env_path);
					frees_tkn(p_tokns);
					return (comname);
				}

				i++;
			}

			frees_getsenv(env_path);
			frees_tkn(p_tokns);
		}

		if (stat(comname, &sh) == 0)
			return (comname);
	}

	free(comname);
	return (NULL);
}

/**
 * exec - Executes a command
 * @comname: The command to execute
 * @opt: The options or flags to the command
 *
 * Return: A integer status value
 */
int exec(char *comname, char **opt)
{
	pid_t child;
	int status;

	switch (child = fork())
	{
		case -1:
			perror("fork failed");
			return (-1);
		case 0:
			execve(comname, opt, environ);
			return (1);
		default:
			do {
				waitpid(child, &status, WUNTRACED);
			} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	return (0);
}
