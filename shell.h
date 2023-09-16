#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

int main();
char **split_string(char *str);
char *get_line(void);
char *_getenv(const char *name);
char *search_exec(char *command);
int exc_fork(char **path, char *argv[], char *envp[]);

// string functions
unsigned int _strspn(char *s, char *accept);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strtok(char *str, const char *delimeter);
int _strcmp(char *s1, const char *s2);
char *_strcpy(char *dest, char *src);
#endif