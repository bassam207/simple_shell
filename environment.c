#include "my_shell.h"

/**
 * print_environment - Prints the environment string to stdout.
 *
 * Return: void
 */
void print_environment(void)
{
    int x = 0;
    char **my_env = my_environ;

    while (my_env[x])
    {
        write(STDOUT_FILENO, my_env[x], my_strlen(my_env[x]));
        write(STDOUT_FILENO, "\n", 1);
        x++;
    }
}
