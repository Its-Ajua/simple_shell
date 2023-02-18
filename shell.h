#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_env(void);
int execbuilt(char **tkn, char *line);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);

#endif
