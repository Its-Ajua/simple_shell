#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_env(void);
int execbuilt(char **tkn char *line);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
void handle_exit(char **tkn, char *line);
char *removeLine(char *s);
char *_getsenv(const char *var);
int word_count(char *s);
int deli_count(char *s, char *deli);

#endif
