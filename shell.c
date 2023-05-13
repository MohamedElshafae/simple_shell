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
	int flag = 1;

	signal(SIGINT, handle_signal);
	while(flag)
	{
		write(STDOUT_FILENO, ">_<$ ", 5);
		flag = getline(&line, &buf_size, stdin);
		if (flag == EOF)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		array_command = get_array_command(line, " ");
		func = get_fun(array_command[0]);
		if (func != NULL)
			func(env, _atoi(array_command[1]));
		else
			fork_execute(array_command, env);
	}
}
void handle_signal(int sig)
{
	if (sig == SIGINT)
		printf("\n>_<$ ");
	fflush(stdout);
}
