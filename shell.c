#include "my_shell.h"

/**
 * main - Main function to carry out the read, execute, then print loop.
 * @argc: Argument count
 * @argv: Argument vector
 * @my_environ: Environment vector
 *
 * Return: 0
 */
struct built_in built_in;
struct information information;
struct my_flags my_flags;
int main(int argc, char **argv, char *my_environ[])
{
	char *input_line = NULL, *command_path = NULL, *search_path = NULL;
	size_t buffer_size = 0;
	ssize_t line_size = 0;
	char **user_command = NULL, **search_paths = NULL;

	(void)my_environ, (void)argv;

	if (argc < 1)
		return (-1);

	signal(SIGINT, handle_signal);

	while (1)
	{
		release_memory(user_command);
		release_memory(search_paths);
		free(command_path);

		display_prompt();
		line_size = getline(&input_line, &buffer_size, stdin);

		if (line_size < 0)
			break;

		information.line_count++;

		if (input_line[line_size - 1] == '\n')
			input_line[line_size - 1] = '\0';

		user_command = tokenize_input(input_line);

		if (user_command == NULL || *user_command == NULL || **user_command == '\0')
			continue;

		if (check_input(user_command, input_line))
			continue;

		search_path = get_search_path();
		search_paths = tokenize_input(search_path);
		command_path = test_search_paths(search_paths, user_command[0]);

		if (!command_path)
			perror(argv[0]);
		else
			execute_command(command_path, user_command);
	}

	if (line_size < 0 && my_flags.interactive)
		write(STDERR_FILENO, "\n", 1);

	free(input_line);
	return (0);
}
