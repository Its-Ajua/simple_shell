#include "shell.h"

int main(void)
{
	char *command = NULL;
	size_t len = 0;
	char *stkn;
	pid_t fa_pid;
	int status, j;

	while (1)
	{
		printf("$ ");
		getline(&command, &len, stdin);

		stkn = strtok(command, " \n");

		char **arr = malloc(sizeof(char *) * 32);

		arr[0] = stkn;

		if (strcmp(arr[0], "exit") == 0)
			exit(0);

		j = 1;

		while (stkn != NULL)
		{
			stkn = strtok(NULL, "  \n");
			arr[j] = stkn;
			j++;
		}

		fa_pid = fork();
		if (strcmp(arr[0], "exit") == 0 && (arr[1] == NULL))
			exit(0);
		if (fa_pid == -1)
		{
			perror("Error");
			return (1);
		}
		else if (fa_pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
			{
				perror(arr[0]);
				return (0);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(command);
	return (0);
}
