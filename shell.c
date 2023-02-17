#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *command = NULL;
	size_t len = 0;
	char *stkn;
	pid_t fa_pid;
	int status;

	while (1)
	{
		printf("$ ");
		getline(&command, &len, stdin);

		stkn = strtok(command, "\n");
		char *arr[] = {stkn, NULL};
		fa_pid = fork();
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
				return (1);
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
