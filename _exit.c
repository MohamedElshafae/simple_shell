#include "shell.h"
/**
 * _hexit - exit the program with a specific statue
 * @env: enviroment var
 * @statue: statue number
 */
void _hexit(char **env, int statue)
{
	(void)env;
	exit(statue);
}
/**
 * print_env - print the enviroment var
 * @env: enviroment var
 * @statue: ...
 */
void print_env(char **env, int statue)
{
	int i;

	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
	(void)statue;
}
