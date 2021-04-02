/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:10:20 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/02 10:19:29 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int	aremoreforme(char **mem, int read_value)
{
	if (!ft_strlen(*mem))
	{
		free(*mem);
		*mem = 0;
		if (read_value == 0)
			return (0);
		return (1);
	}
	return (1);
}

int	makeline(char **mem, char **line, int read_value)
{
	char	*new_line;
	char	*new_mem;
	size_t	i;
	size_t	j;

	i = ft_strlen(mem[0]);
	j = 0;
	while (mem[0][j] && mem[0][j] != '\n')
		j++;
	if (safe_malloc(&new_line, j) == -1)
		return (fsm(mem, 0, -1));
	*line = new_line;
	j = 0;
	while (mem[0][j] && mem[0][j] != '\n')
		*(new_line)++ = mem[0][j++];
	if (safe_malloc(&new_mem, i - j) == -1)
		return (fsm(mem, &new_line, -1));
	i = 0;
	while (mem[0][j] && mem[0][++j])
		new_mem[i++] = mem[0][j];
	free(*mem);
	*mem = new_mem;
	return (aremoreforme(mem, read_value));
}

int	update_line(char **src, char **dst, int fd)
{
	char	*updated_line;
	char	*aux;
	int		read_value;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	read_value = safe_read(&aux, fd);
	if (read_value == -1)
		return (fsm(src, 0, -1));
	if (safe_malloc(&updated_line, ft_strlen(*src) + ft_strlen(aux)) == -1)
		return (fsm(src, 0, -1));
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

int	get_next_line(int fd, char **line)
{
	static char	*mem[4096];
	char		*buffer;
	int			read_value;

	buffer = 0;
	if (line == 0 || fd == -1 || BUFFER_SIZE < 1)
		return (-1);
	if (mem[fd])
	{
		if (nlin(mem[fd]))
			return (makeline(&mem[fd], line, BUFFER_SIZE));
		else
			read_value = update_line(&mem[fd], &buffer, fd);
	}
	else
		read_value = safe_read(&buffer, fd);
	while (read_value == BUFFER_SIZE && !nlin(buffer))
		read_value = update_line(&buffer, &buffer, fd);
	if (read_value == -1)
		return (fsm(&buffer, 0, -1));
	mem[fd] = buffer;
	if (!nlin(mem[fd]))
		read_value = 0;
	return (makeline(&mem[fd], line, read_value));
}
