/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:00:14 by manmarti          #+#    #+#             */
/*   Updated: 2021/04/02 10:15:45 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>

int		nlin(char *str);
int		safe_malloc(char **loc, size_t size);
int		safe_read(char **buffer, int fd);
size_t	ft_strlen(char *str);
int		get_next_line(int fd, char **line);
int		fsm(char **mem1, char **mem2, int return_value);

#endif