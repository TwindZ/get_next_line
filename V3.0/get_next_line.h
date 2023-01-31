#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // TODO a enlever avant de push
#include <fcntl.h> // TODO a enlever avant de push

void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);


# endif

