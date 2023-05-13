#include "shell.h"

/**
 * fork_excute - make a fork and excute a command
 * @command_array: command array that will be excuted
 * Return: 0 on success and 1 in fail
 */
int fork_execute(char **command_array, char **env)
{
	pid_t id;
	int statue, i = 0;
	char *path = get_path(env);
	char **array_path = get_array_command(path, ":");
	char *catpath = command_array[0];

	while (array_path[i])
	{
		if (i != 0)
		{
			catpath = malloc(_strlen(array_path[i]) + _strlen(command_array[0]) + 1);
			_strcpy(catpath, array_path[i]);
			_strcat(catpath, "/");
			_strcat(catpath, command_array[0]);
		}

		if (access(catpath, X_OK) == 0)
		{
			id = fork();
			if (id == 0)
			{
				execve(catpath, command_array, env);
				break;
			}
			else
			{
				wait(&statue);
				return (0);

			}
		}
		i++;
	}
	free(catpath);
	free(array_path);
	free(command_array);
	return (1);
}
