#ifndef MAIN_H
#define MAIN_H
#define BUF_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **get_array_command(char *line, char *del);
int fork_execute(char **command_array, char **env);
char *get_path(char **env);
#endif
