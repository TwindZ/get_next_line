/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:19:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/02 14:30:38 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_stack(int fd, char *stack)
{
	int		ret;
	char	*buf;
	
	ret = 1;
	while(ret > 0 && ft_strchr(stack, '\n') == NULL)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (NULL);
		ret = read(fd, buf, BUFFER_SIZE);
		if(ret == -1)
		{
			free(buf);
			return (NULL);
		}
		stack = ft_strjoin(stack, buf);
		free(buf);
	}
	return(stack);
}

char	*ft_over(char *stack)
{
	char	*over;
	int		stacklen;
	int		i;

	i = 0;
	stacklen = ft_strlen(stack);
	while(stack[i] && stack[i] != '\n')
		i++;
	over = calloc((stacklen - i) + 2, sizeof(char));
	if(!over)
		return (NULL);
	over = ft_memcpy(over, stack + i + 1, stacklen - i);//+2?
	free(stack);
	return(over);
}

char	*ft_line(char *stack)
{
	char 	*line;
	int		stacklen;
	int		i;

	i = 0;
	stacklen = ft_strlen(stack);
	while(stack[i] && stack[i] != '\n')
		i++;
	line = calloc((stacklen - (stacklen - i)) + 2, sizeof(char)); //+2?
	if(!line)
		return (NULL);
	line = ft_memcpy(line, stack, i + 1);//+2
	return(line);
	
}
char	*get_next_line(int fd)
{
	char		*line;
	char static *stack;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(read(fd, NULL, BUFFER_SIZE) == 0)
		return (NULL);
	stack = ft_stack(fd, stack);
	if(!stack)
		return (NULL);
	line = ft_line(stack);
	stack = ft_over(stack);
	if(!line)
		return(NULL);
	return (line);
}
