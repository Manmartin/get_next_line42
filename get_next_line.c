#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int aremoreforme(char **mem, int read_value)
{
	if (!ft_strlen(*mem))
	{
		free(*mem);
		*mem = 0;
		if (read_value != BUFFER_SIZE)
			return (0);
		return (1);
	}
	return (1);
}

int makeline(char **mem, char **line, int read_value)
{
	char *new_line;
	char *new_mem;
	size_t i;
	size_t j;

	if (!mem)
		return (0);
	i = ft_strlen(mem[0]);
	while (mem[0][j] && mem[0][j] != '\n')
		j++;
	if (safety_malloc(&new_line, j) == -1)
		return(-1);
	*line = new_line;
	j = 0;
	while (mem[0][j] && mem[0][j] != '\n')
		*(new_line)++ = mem[0][j++];
	if (safety_malloc(&new_mem, i - j) == -1)
		return(-1);
	i = 0;
	while (mem[0][j] && mem[0][++j])
		new_mem[i++] = mem[0][j];
	free(*mem);
	*mem = new_mem;
	return (aremoreforme(mem, read_value));
}

int update_line(char **src, char **dst, int fd)
{
	char	*updated_line;
	char	*aux;
	int		read_value;
	size_t	i;
	size_t 	j;

	i = 0;
	j = 0;
	read_value = safety_read(&aux, fd);
	if (read_value == -1)
		return(-1);
	if (safety_malloc(&updated_line, ft_strlen(*src) + ft_strlen(aux)) == -1)
		return (-1);
	while (src[0][i])
		updated_line[j++] = src[0][i++];
	i = 0;
	while (aux[i])
		updated_line[j++] = aux[i++];
	free(*src);
	*src = 0;
	free(aux);
	*dst = updated_line;
	return (read_value);
}

int	get_next_line(char **line, int fd)
{
	static char *mem = 0;
	char		*buffer;
	int			read_value;

	buffer = 0;
	if (line == 0 || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if  (mem)
	{
		if (nlin(mem))
			return (makeline(&mem, line, BUFFER_SIZE));
		else
			read_value = update_line(&mem, &buffer, fd);
	}
	else
		read_value = safety_read(&buffer, fd);
	while (read_value == BUFFER_SIZE && !nlin(buffer))
		read_value = update_line(&buffer, &buffer, fd);
	if (read_value == -1)
		return (-1);
	mem = buffer;
	return (makeline(&mem, line, read_value));
}
