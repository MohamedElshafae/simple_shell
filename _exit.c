#include "shell.h"

void _hexit(char **env, int statue)
{
	(void)env;
	exit(statue);
}
void print_env(char **env, int statue)
{
	(void)statue;
	printf("env\n");
}
