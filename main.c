#include "shell.h"
/**
 * sigint_handler - function to send signal for ctrl + c
 */
void sigint_handler()
{
	char *prompt_shell = "\n#cisfun$ ";

	write(STDOUT_FILENO, prompt_shell, _strlen(prompt_shell));
}
/**
 * interactive_mode - shell interaction mode
 * @argv: array of argument
 * @env: the environment
 */
void interactive_mode(char **argv, char **env)
{
	char *line;
	char **tokens;
	char *prompt_shell = "#cisfun$ ";
	int len = _strlen(prompt_shell);
	int number = 0;


	while (1)
	{
		if (signal(SIGINT, sigint_handler) == SIG_ERR)
		{
			perror("signal");
			exit(EXIT_FAILURE);
		}
		write(STDOUT_FILENO, prompt_shell, len);
		line = prompt();
		if (line == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(line);
		}
		tokens =  _split(line);
		if (tokens == NULL)
		{
			continue;
		}
		number++;
		execute(tokens, argv, env, number);
	}
}

/**
 * main -my own shell program
 * @argc: number of argument
 * @argv: array of argumemnt
 * @env: environment
 * Return: 0 if success, otherwise -1
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{

	char *line;
	/*char *command[] = {NULL, NULL};*/
	char **tokens;
	int number = 0;

	if (isatty(STDIN_FILENO) == 1) /*check if we are in interactive mode*/
	{
		interactive_mode(argv, env);
	}
	else
	{
		while (1)
		{
			/*line = non_interactive();*/
			line = prompt();
			if (line == NULL)
			{
				/*write(STDOUT_FILENO, "\n", 1);*/
				free(line), line = NULL;
				exit(EXIT_SUCCESS);
			}
			tokens = _split(line);
			if (tokens == NULL)
				continue;
			number++;
			execute(tokens, argv, env, number);
		}
	}
	return (0);
}

