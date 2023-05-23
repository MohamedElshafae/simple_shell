#include "shell.h"

/**
 * calc_size - calculate the buffer
 * @n:buffersize
 * @input:number of byte
 * Return:void
 */
void calc_size(size_t *n, int input)
{
	if (input >= BUFSIZE)
		*n = input;
	else
		*n = BUFSIZE;
}

/**
 * _getline - get line from file
 * @line:array of string
 * @n:buffer size
 * @fd:file descriptor
 * Return:number of byte or -1 if failed
 */
ssize_t _getline(char **line, size_t *n, int fd)
{
	int check;
	static size_t input;
	int inp;
	char *buffer;
	char ch;

	if (input == 0)
		fflush(STDIN_FILENO);
	else
		return (-1);
	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (ch != '\n')
	{
		check = read(fd, &ch, 1);
		if (check == -1 || (check == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (check == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = realloc(buffer, input + 1);
		buffer[input++] = ch;
	}
	buffer[input] = '\0';
	*line = buffer;
	calc_size(n, input);
	inp = input;
	if (check != 0)
		input = 0;
	return (inp);
}
