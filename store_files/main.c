#include "shell.h"

/**
 * main - Checks for a command prompt and executes
 *
 * Return: 0 on success
 */

int main(void)
{
	char *command = NULL, **tkn = NULL;
	int length = 0, flag = 0;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (line_len >= 0)
	{
		signal(SIGINT, sign_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_len = getline(&command, &line_size, stdin);
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		length = word_count(command);
		if (command[0] != '\n' && length > 0)
		{
			tkn = tokenize(command, " \t", length);
			flag = execbuilt(tkn, command);
			if (!flag)
			{
				tkn[0] = find(tkn[0]);
				if (tkn[0] && access(tkn[0], X_OK) == 0)
					exec(tkn[0], tkn);
				else
					perror("./hsh");
			}

			frees_tkn(tkn);
		}
	}

	free(command);
	return (0);
}
