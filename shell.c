#include "shell.h"

void handle_signal();
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
		array_lines = get_array_command(line, ";");
		while (array_lines[j])
		{
			array_command = get_array_command(array_lines[j], " ");
			func = get_fun(array_command[0]);
			statue = array_command[1] ? _atoi(array_command[1]) : 0;
			if (func != NULL)
				func(env, statue);
			else
				fork_execute(array_command, env);
			j++;
		}
	}
}
void handle_signal(int sig)
{
	if (sig == SIGINT)
		printf("\n>_<$ ");
	fflush(stdout);
}
