#include "shell.h"

int main()
{
    char *prompt = "#cisfun$ ";
    char *line;
    char **str;

    while (1)
    {
        printf("%s", prompt);
        fflush(stdout);

        line = get_line();

        str = split_string(line);

        exec_fork();

        free(line);
        free(str);
    }

    return 0;
}
