#ifndef MY_SHELL_H
#define MY_SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* Environment variables */
extern char **my_environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* Handle built-ins */
int check_input(char **cmd, char *buf);
void display_prompt(void);
void handle_interrupt(int m);
char **tokenize_input(char *line);
char *test_search_paths(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_command(char **command, char *line);

void print_environment(void);

/* String handlers */
int my_strcmp(char *s1, char *s2);
int my_strlen(char *s);
int my_strncmp(char *s1, char *s2, int n);
char *my_strdup(char *s);
char *my_strchr(char *s, char c);

void execute_command(char *cp, char **cmd);
char *get_search_path(void);

/* Helper function for efficient free */
void release_memory(char **buffers);

struct built_in
{
    char *env;
    char *exit;
} built_in;

struct information
{
    int final_exit;
    int line_count;
} information;

struct my_flags
{
    bool interactive;
} my_flags;

#endif /* MY_SHELL_H */

