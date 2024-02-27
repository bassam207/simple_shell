#include "my_shell.h"

/**
 * find_path - Finds the path from the global environment.
 *
 * Return: NULL if path is not found or path if path is found.
 */
char *find_path(void)
{
    int x = 0;
    char **my_env = my_environ;
    char *path = NULL;

    while (*my_env)
    {
        if (my_strncmp(*my_env, "PATH=", 5) == 0)
        {
            path = *my_env + 5; // Skip "PATH="
            return path;
        }
        my_env++;
    }
    return NULL;
}
