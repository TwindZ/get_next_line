#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // TODO a enlever avant de push
#include <fcntl.h> // TODO a enlever avant de push

struct s_var{
	char static *over;
}t_var;

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

# endif
# endif

