#include "shell.h"

/**
 * atoi - convert string to int
 * @str: string
 * Return: intger converted from string
 */
int _atoi(char *str)
{
	int i, num;
	int len = _strlen(str);

	if (str[0] >= '0' && str[0] <= '9')
		num = str[0] - '0';
	else
		return (0);
	for (i = 1; i < len; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num *= 10;
			num += str[i] - '0';
		}
		else
			return (0);
	}
	return (num);
}

/**
 * _strlen -  calculate length of string
 * @str:string var
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
