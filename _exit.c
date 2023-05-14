#include "shell.h"

void _hexit(char **env, int statue)
{
	(void)env;
	exit(statue);
}
void print_env(char **env, int statue)
{
	int i;

	for (i = 0; env[i]; i++)
	       printf("%s\n", env[i]);	
	(void)statue;
}
