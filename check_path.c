#include "my_shell.h"

/**
 * test_search_paths - Checks whether path is valid.
 * @search_paths: Tokenized path.
 * @command: User entered command.
 *
 * Return: Path appended with command on success, NULL on failure.
 */
char *test_search_paths(char **search_paths, char *command)
{
    int i = 0;
    char *output;

    while (search_paths[i])
    {
        output = append_path(search_paths[i], command);
        if (access(output, F_OK | X_OK) == 0)
            return (output);
        free(output);
        i++;
    }
    return (NULL);
}
