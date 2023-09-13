#include "shell.h"

char **split_string(char *str)
{
    int cur_position = 0;
    char **tokens;
    int i;
    int count = 0;
    char *token;
    char *dup_str;

    dup_str = strdup(str);
    token = _strtok(dup_str, " \t\n");

    while (token != NULL)
    {
        cur_position++;
        token = _strtok(NULL, " \t\n");
    }
    tokens = malloc((cur_position + 1) * sizeof(char *));
    if (tokens == NULL)
    {
        free(tokens);
        return NULL;
    }

    token = _strtok(str, " \t\n");
    while (token != NULL)
    {
        tokens[count++] = strdup(token);

        token = _strtok(NULL, " \t\n");
    }
    tokens[count] = NULL;

    for (i = 0; i < count; i++)
    {
        printf("%s\n", tokens[i]);
    }

    free(dup_str);
    return (tokens);
}
