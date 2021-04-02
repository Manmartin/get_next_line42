/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 20:59:29 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/02 10:33:19 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	nlin(char *str)
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

int	safe_malloc(char **loc, size_t size)
{
	char	*aux;

	aux = (char *)malloc(sizeof(char) * (size + 1));
	if (!aux)
		return (-1);
	*loc = aux;
	while (size--)
		*(aux++) = 0;
	*aux = 0;
	return (1);
}

int	safe_read(char **buffer, int fd)
{
	int	read_value;

	if (safe_malloc(buffer, BUFFER_SIZE) == -1)
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

int	fsm(char **mem1, char **mem2, int return_value)
{
	if (mem1)
	{
		if (*mem1)
		{
			free(*mem1);
			*mem1 = 0;
		}
	}
	if (mem2)
	{
		if (*mem2)
		{
			free(*mem2);
			*mem2 = 0;
		}
	}
	return (return_value);
}
