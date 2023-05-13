#include "shell.h"

/**
 * main:...
 * @argc: number of arguments
 * @argv: array of arguments
 * @env: enviroment
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	char *line = NULL;
	size_t buf_size = 0;
	char **array_command = NULL;

	while(1)
	{
		write(STDOUT_FILENO, ">_<$ ", 5);
		getline(&line, &buf_size, stdin);
		array_command = get_array_command(line, " ");
		fork_execute(array_command, env);
	}
}
