#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> // TODO a enlever avant de push
#include <fcntl.h> // TODO a enlever avant de push

char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);

void		*ft_memset(void *s, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_calloc(size_t count, size_t size);

# endif
# endif

