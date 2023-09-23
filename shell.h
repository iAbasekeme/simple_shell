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

<<<<<<< HEAD
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
=======
extern char **environ;

int main(int ac, char *argv[], char *env[]);
char **split_string(char *str);
char *get_line(void);
char *_getenv(char *name);
char *search_exec(char *command);
int check_exit_status(char *str);
char *search_exec(char *command);
int _exc_fork(char **path, char *argv[], char *envp[]);
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb

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
<<<<<<< HEAD
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

=======
char *_strcat(char *dest, char *src);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strdup(char *str);
>>>>>>> 79099a6883339fa0e057ba90257bb155bbb24edb
#endif

