#include "my_shell.h"

/**
 * handle_signal - handles the signal to maintain interactivity
 * @signal_number: the signal number received
 * Return: void
 */
void handle_signal(int signal_number)
{
    (void)signal_number;
    write(STDERR_FILENO, "\n", 1);
    write(STDERR_FILENO, "$ ", 2);
}
