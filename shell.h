#ifndef MAIN_H
#define MAIN_H
#define BUF_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct builtins - struct to map each builtin command to a fun
 * @cmd: the command
 * @funptr: ptr to the function
 */
typedef struct builtins
{
	char *cmd;
	void (*funptr)();
} fun_t;
char **get_array_command(char *line, char *del);
int fork_execute(char **command_array, char **env);
char *get_path(char **env);
void (*get_fun(char *str))();
void _hexit(char **env, int statue);
void print_env(char **env, int statue);


char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
int _strncmp(char *s1, char *s2, int count);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
#endif
