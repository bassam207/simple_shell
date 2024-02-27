#include "my_shell.h"

/**
 * exit_command - Handles the exit command.
 * @command: Tokenized command.
 * @line: Input read from stdin.
 *
 * Return: No return.
 */
void exit_command(char **command, char *line)
{
    free(line);
    release_memory(command);
    exit(0);
}
