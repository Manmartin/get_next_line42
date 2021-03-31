#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>

int		nlin(char *str);
int		safety_malloc(char **loc, size_t size);
int		safety_read(char **buffer, int fd);
size_t	ft_strlen(char *str);
int		get_next_line(char **line, int fd);

#endif