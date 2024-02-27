#include "my_shell.h"

/**
 * _putchar - Writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned and errno set appropriately.
 */
int _putchar(char c)
{
    return (write(STDOUT_FILENO, &c, 1));
}

/**
 * print_string - Prints a string.
 * @s: String to be printed.
 *
 * Return: Number of characters printed.
 */
int print_string(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        _putchar(s[i]);
        i++;
    }

    return (i);
}
