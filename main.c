#include "shell.h"

int main(int ac, char *argv[], char *env[])
{
	(void)ac;

	char *prompt = "#cisfun$ ";
	char *line;
	char **str;
	int exp_fork;
	int i = 0;

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);

		line = get_line();

		str = split_string(line);
		printf("first command: %s\n", str[0]);

		exp_fork = exc_fork(str, argv, env);

		// printf()
		// printf("%s", search_ex);
		// exec = exc_fork(command);
		// if (exec == 0)
		// {
		// 	perror("exec_fork");
		// }

		free(str);
	}

	return 0;
}
