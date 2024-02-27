#include "my_shell.h"

/**
 * display_prompt - Prints $ to let user know the program is ready to take their input.
 * Prints the prompt if the shell is in interactive mode.
 *
 * Return: No return.
 */
void display_prompt(void)
{
    if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
        my_flags.interactive = 1;
    if (my_flags.interactive)
        write(STDERR_FILENO, "$ ", 2);
}
