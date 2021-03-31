#include "get_next_line.h"
#include <stdlib.h>

size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

int nlin(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}


int safety_malloc(char **loc, size_t size)
{
	char *aux;

	aux = (char *)malloc(sizeof(char) * (size + 1));
	if (!aux)
		return (-1);
	*loc = aux;
	while (size--)
		*(aux++) = 0;
	*aux = 0;
	return (1);
}

int safety_read(char **buffer, int fd)
{
	int read_value;

	if (safety_malloc(buffer, BUFFER_SIZE) == -1)
		return (-1);
	read_value = read(fd, *buffer, BUFFER_SIZE);
	if (read_value < 0)
	{
		free(*buffer);
		*buffer = 0;
		return (-1);
	}
	return (read_value);
}
