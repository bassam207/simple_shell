#include "my_shell.h"

/**
 * handle_builtin - Handles execution of built-in functions.
 * @command: Tokenized commands.
 * @line: Input read from stdin.
 *
 * Return: 1 if executed, 0 if not.
 */
int handle_builtin(char **command, char *line)
{
    struct built_in built_in = {"env", "exit"};

    if (my_strcmp(*command, built_in.env) == 0)
    {
        print_environment();
        return (1);
    }
    else if (my_strcmp(*command, built_in.exit) == 0)
    {
        exit_command(command, line);
        return (1);
    }
    return (0);
}
