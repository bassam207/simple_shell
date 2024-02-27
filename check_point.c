#include "my_shell.h"

/**
 * check_input - Checks whether it's a built-in function.
 * @user_command: Tokenized user input.
 * @input_line: Line derived from getline function.
 *
 * Return: 1 if command executed, 0 if command is not executed.
 */
int check_input(char **user_command, char *input_line)
{
    if (handle_builtin(user_command, input_line))
        return (1);
    else if (**user_command == '/')
    {
        execute_command(user_command[0], user_command);
        return (1);
    }
    return (0);
}
