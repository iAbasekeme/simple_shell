#ifndef SHELL_H
#define SHELL_H
#define EXIT_CODE 1080

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

#define CD 5863276
#define EXIT 6385204799
#define ECHO 6385181892
#define SET 193505681
#define SETENV 6954013771834
#define UNSETENV 7573017818690365
#define ENV 193490734
#define TOKEN_BUFSIZE 64

/**
 * struct builtin_command - Short description
 * @name: First member
 * @function: Second member
 *
 * Description: Longer description
 */
struct builtin_command
{
	char *name;
	int (*function)(char **array_of_tokens);
};

extern char **envp;
void prompt(void);
void sigint_handler(int signal);
ssize_t _getline(char **input,
		size_t *number_of_malloc_bytes_allocated, int status);
char **array_maker(char *input, char *delimiter);
int _fork(char *command, char **array_of_tokens);
char *_which(char *filename);
int _print_env(void);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *malloc_char(char **string, size_t size_of_malloc, char *error_message);
char **malloc_array(char **array, size_t size_of_malloc, char *error_message);
int copy_array(char **destination, char **source);
int _env_name_exists(const char *name);
int _env_length(void);
void free_which(char **path_var, char **array_of_tokens);
void free_main(char **array_of_tokens, char *input);
void rev_string(char *s);
char *_itoa(size_t command_num);
int digit_counter(size_t command_num);
int error_not_found(char **arvs, char **array_of_tokens, size_t command_num);
int is_builtin(char **array_of_tokens);
int builin_handler(char **array_of_tokens);
int _exit_builtin(char **array_of_tokens);
int _env_builtin(char **array_of_tokens);
int non_inter_mode(int argc, char **argv, char **envp);
unsigned long hash(const char *str);
void free_vector(char **argv);
void myprintf(const char *datas);
void process_setenv(char **envp);
int executecmd(char **argv, char **envp, char *line);
char **tokenize(char *str);
char *_getenv(char *name, char **envp);
int _atoi(char *s);
void exitshell(char **tokk, char *line);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_getpath(char *strings, char ** envp);
int process(char **command, char **envp);
int change_dir(char **command, char **envp);
int main(int argc, char **argv, char **envp);
ssize_t _getline(char **lineptr, FILE *stream);
char *_strdup(const char *str);
char *_strchr(char *s, char c);
void print_env(char **argv, char **envp);
void set_env_var(char **args);
void un_set_env_var(char **args);
int cd_dir(char **argv, char **envp);
int interract(int argc, char **argv, char **envp);
int _getppid(char **argv);

#endif
