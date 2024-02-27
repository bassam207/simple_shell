#include "my_shell.h"

/**
 * release_memory - Frees buffers.
 * @buffers: Buffer to be freed.
 *
 * Return: No return.
 */
void release_memory(char **buffers)
{
    int i = 0;

    if (!buffers || buffers == NULL)
        return;

    while (buffers[i])
    {
        free(buffers[i]);
        i++;
    }
    free(buffers);
}
