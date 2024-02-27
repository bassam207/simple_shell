#include "my_shell.h"

/**
 * get_search_path - Finds the path from the global environment.
 *
 * Return: NULL if path is not found or path if path is found.
 */
char *get_search_path(void)
{
    char **my_env = my_environ;
    char *path = NULL;

    while (*my_env)
    {
        if (my_strncmp(*my_env, "PATH=", 5) == 0)
        {
            path = *my_env + 5;
            return path;
        }
        my_env++;
    }
    return NULL;
}
