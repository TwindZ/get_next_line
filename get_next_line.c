/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:19:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/28 18:47:04 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strbrk(char *buf, int i, char *save, char static *over)
{	
	char			*brk
	while(brk[i])
	{
		if(brk[i] == '\n')
		{
			ft_memset(save, 0, BUFFER_SIZE + 1);
			ft_memcpy(save, brk, i + 1);
			ft_memset(over, 0, BUFFER_SIZE + 1);
			ft_memcpy(over, brk + (i), BUFFER_SIZE - i);
			return(save);
		}
		else if(brk[i + 1] == '\0')
			return(brk);
		i++;
	}
}

char	*ft_switch(char *buf, int i, char *save)
{
	char static		*over;
		
	if(!over)
		over = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if(over[i] !='\0')
		save = ft_strbrk(over, 0, save, over);
	else
		save = ft_strbrk(buf, 0, save, over);
	return (save);
		
}

char	*get_next_line(int fd)
{
	char			*buf;
	unsigned int	ret;
	char			*line;
	char			*save;

	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	save = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while(line[ft_strlen(line) - 1] != '\n')
	{
		buf = ft_memset(buf, 0, BUFFER_SIZE + 1);
		ret = read(fd, buf, BUFFER_SIZE);
		if(ret == 0)
		{
			if(line[0] != '\0')
				return(line);
			return(NULL);
		}
		line = ft_strjoin(line, (const char *)ft_switch(buf, 0, save));
	}
	return(line);
}
