#include "my_shell.h"

/**
 * tokenize_input - Creates tokens from given input.
 * @input_line: Input line to be tokenized.
 *
 * Return: Array of strings containing tokens.
 */
char **tokenize_input(char *input_line)
{
    char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
    char **tokens = NULL;
    int token_count = 1;
    size_t index = 0, flag = 0;

    buf = my_strdup(input_line);
    if (!buf)
        return (NULL);
    bufp = buf;

    while (*bufp)
    {
        if (my_strchr(delim, *bufp) != NULL && flag == 0)
        {
            token_count++;
            flag = 1;
        }
        else if (my_strchr(delim, *bufp) == NULL && flag == 1)
            flag = 0;
        bufp++;
    }

    tokens = malloc(sizeof(char *) * (token_count + 1));
    if (!tokens)
    {
        free(buf);
        return (NULL);
    }

    token = strtok(buf, delim);
    while (token)
    {
        tokens[index] = my_strdup(token);
        if (!tokens[index])
        {
            free(tokens);
            free(buf);
            return (NULL);
        }
        token = strtok(NULL, delim);
        index++;
    }
    tokens[index] = NULL;
    free(buf);
    return (tokens);
}
