#include "my_shell.h"

/**
 * my_strcmp - Compares two strings.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 *
 * Return: Returns difference between strings.
 */
int my_strcmp(char *s1, char *s2)
{
    int i = 0, output;

    while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
        i++;

    output = (*(s1 + i) - *(s2 + i));

    return (output);
}

/**
 * my_strlen - Returns the length of a string.
 * @s: String passed.
 *
 * Return: Returns length of string passed.
 */
int my_strlen(char *s)
{
    int count = 0;

    while (*s != '\0')
    {
        count++;
        s++;
    }
    return (count);
}

/**
 * my_strncmp - Compares two strings up to n bytes.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @n: Number of bytes.
 *
 * Return: Difference between s1 and s2.
 */
int my_strncmp(char *s1, char *s2, int n)
{
    int i;

    for (i = 0; s1[i] && s2[i] && i < n; i++)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

/**
 * my_strdup - Duplicates string.
 * @s: String to be duplicated.
 *
 * Return: Pointer to duplicate string.
 */
char *my_strdup(char *s)
{
    char *ptr;
    int i, len;

    if (s == NULL)
        return (NULL);

    len = my_strlen(s);

    ptr = malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);
    for (i = 0; *s != '\0'; s++, i++)
        ptr[i] = s[0];

    ptr[i++] = '\0';
    return (ptr);
}

/**
 * my_strchr - Locates a character in a string.
 * @s: String to be checked.
 * @c: Character to be located.
 *
 * Return: Returns pointer to first occurrence of character
 * or NULL if character not found.
 */
char *my_strchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    if (!c)
        return (s);
    return (NULL);
}
