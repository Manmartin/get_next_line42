#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <unistd.h>

int		nlin(char *str);
int		safe_malloc(char **loc, size_t size);
int		safe_read(char **buffer, int fd);
size_t	ft_strlen(char *str);
int		get_next_line(int fd, char **line);
int		fsm(char **mem1, char **mem2, int return_value);

#endif