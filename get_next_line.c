/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:19:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/31 11:04:17 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fread(int fd, char *buf)
{		
	int	ret;
	
	ft_bzero(buf, BUFFER_SIZE + 1);
	ret = read(fd, buf, BUFFER_SIZE);
	if(ret == 0 || ret == -1)
		return(NULL);
	return(buf);
}

char	*ft_strbrk(char *brk, int i, char *save, char *over)
{		
	ft_bzero(save, BUFFER_SIZE + 1);	
	while(brk[i])
	{
		if(brk[i] == '\n')
		{
			ft_memcpy(save, brk, i + 1);
			ft_memcpy(over, brk + (i + 1), BUFFER_SIZE - (i));
			return(save);
		}
		else if(brk[i + 1] == '\0')
		{

			ft_memcpy(save, brk, i + 1);
			ft_bzero(over, BUFFER_SIZE + 1);
			return(save);
		}
		i++;
	}
	return (save);
}

char	*ft_switch(char *buf, int i, char *save, char *over)
{	
		
	if(over[i] != '\0')
		save = ft_strbrk(over, 0, save , over);
	else
		save = ft_strbrk(buf, 0, save, over);
	return (save);
		
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*line;
	char			*save;
	char static		*over;

	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	save = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!over)
		over = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while(line[ft_strlen(line) - 1] != '\n')
	{
		if(over[0] == '\0')
			buf = ft_fread(fd, buf);
		if(buf == NULL)
		{	
			if(line == NULL)
				return(NULL);	
			return (line);
		}
		line = ft_strjoin(line, ft_switch(buf, 0, save, over));
	}
	return(line);
}
