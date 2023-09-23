#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

/**
 * struct builtin - structure hold command name and function
 * @name: name of command
 * @f: specific function
 */
struct builtin
{
	char *name;
	void (*f)(char **tokens);
};

char *prompt(void);
char **_split(char *input);
int execute(char **tokens, char **argv, char **env, int number);
char *non_interactive();
char *get_path(char *tokens);
void free_array(char **tokens);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_getenv(char *va_env);
int _strcmp(char *s1, char *s2);
char *_str_concate(char *dest, char *src);
void erro_mess(char *name, char *input, int number);
int my_exit(char *input);
void my_env(char **env);
char *convert_number(int num);
void erro_mess(char *name, char *input, int number);
ssize_t _getline(char **lineptr, size_t *n, int fd);
int my_setenv(char *name, char *value, int overwrite);
int my_unsetenv(char *name);
void my_cd(char **tokens);
int _strcmp(char *s1, char *s2);

#endif

