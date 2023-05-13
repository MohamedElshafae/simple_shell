#include "shell.h"

/**
 * get_path - get path from environment
 * @env: environment from main
 * Return:path
 */

char *get_path(char **env)
{
	int i = 0, j, len;
	char *PATH, *sp_start = "path:";

	while (_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i] == NULL)
		return (NULL);
	len = _strlen(env[i]);
	PATH = malloc(sizeof(char) * (len + 1));
	if (!PATH)
		return (NULL);
	for (j = 0; j < len; j++)
	{
		if (j < 5)
			PATH[j] = sp_start[j];
		PATH[j] = env[i][j];
	}
	PATH[j] = '\0';
	return (PATH);
}
