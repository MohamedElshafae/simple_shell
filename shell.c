#include "shell.h"

void handle_signal(int sig);
/**
 * main - ...
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
	void (*func)();
	int j, flag = 1;
	int statue;
	char **array_lines = NULL;

	signal(SIGINT, handle_signal);
	while (flag)
	{
		j = 0;
		write(STDOUT_FILENO, ">_<$ ", 5);
		flag = getline(&line, &buf_size, stdin);
		if (flag == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (_strcmp(line, "\n") == 0)
			continue;
		array_lines = get_array_command(line, ";");
		while (array_lines[j])
		{
			array_command = get_array_command(array_lines[j], " ");
			func = get_fun(array_command[0]);
			statue = array_command[1] ? _atoi(array_command[1]) : 0;
			if (func != NULL)
			{
				arg_t args;
				args.env = env;
				args.statue = statue;
				args.array_command = array_command;
				func(args);
			}
			else
				fork_execute(array_command, env);
			j++;
		}
	}
}
/**
 * handle_signal - handle ctrl + c
 * @sig: signal to handle
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
		printf("\n>_<$ ");
	fflush(stdout);
}
