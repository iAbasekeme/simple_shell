#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

int main(int ac, char *argv[], char *env[]);
char **split_string(char *str);
int *get_line(char **a, size_t *b, ...);
char *_getenv(const char *name);
char *search_exec(char *command);
int exc_fork(char **path, char *argv[], char *envp[]);

unsigned int _strspn(char *s, char *accept);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strdup(const char *str);
#endif
