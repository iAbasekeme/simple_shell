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

int main();
char **split_string(char *str);
char *get_line(void);
int exc_fork(const char **path, char *const argv[], char *const envp[]);

// string functions
unsigned int _strspn(char *s, char *accept);
int _strlen(char *s);
char *_strchr(char *s, char c);
char *_strtok(char *str, const char *delimeter);

#endif