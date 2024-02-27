#include "my_shell.h"

/**
 * execute_command - Executes commands entered by users.
 * @cp: Command path.
 * @cmd: Vector array of pointers to commands.
 * 
 * Return: void
 */
void execute_command(char *cp, char **cmd)
{
    pid_t child_pid;
    int status;
    char **my_env = my_environ;

    child_pid = fork();
    if (child_pid < 0)
        perror(cp);
    if (child_pid == 0)
    {
        execve(cp, cmd, my_env);
        perror(cp);
        free(cp);
        release_memory(cmd);
        exit(98);
    }
    else
        wait(&status);
}
