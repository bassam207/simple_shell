#include "my_shell.h"

/**
 * append_path - Adds path to command.
 * @search_path: Path of command.
 * @user_command: User-entered command.
 *
 * Return: Buffer containing command with path on success, NULL on failure.
 */
char *append_path(char *search_path, char *user_command)
{
    char *buffer;
    size_t i = 0, j = 0;

    if (user_command == NULL)
        user_command = "";

    if (search_path == NULL)
        search_path = "";

    buffer = malloc(sizeof(char) * (my_strlen(search_path) + my_strlen(user_command) + 2));
    if (buffer == NULL)
        return (NULL);

    while (search_path[i])
    {
        buffer[i] = search_path[i];
        i++;
    }

    if (search_path[i - 1] != '/')
    {
        buffer[i] = '/';
        i++;
    }

    while (user_command[j])
    {
        buffer[i + j] = user_command[j];
        j++;
    }

    buffer[i + j] = '\0';
    return (buffer);
}
