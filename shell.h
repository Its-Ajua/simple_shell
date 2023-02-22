#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;


void print_env(void);
int execbuilt(char **tkn, char *line);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(const char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);
void handle_exit(char **tokn, char *line);
char *removeLine(char *s);
char *_getsenv(const char *var);
int word_count(char *s);
int deli_count(char *s, char *deli);
int exec(char *comname, char **opt);
char *find(char *comname);
void frees_getsenv(char *envipath);
void frees_tkn(char **tkn);
void sign_handler(int signal_id);
char **tokenize(char *str, char *del, int len);
int _atoi(char *s);
void _puts(char *s);
int _strncmp(const char *s1, const char *s2, size_t length);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void open_help(void);

#endif
