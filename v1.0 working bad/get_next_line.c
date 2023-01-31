/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:19:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/27 22:37:50 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*over;
	char		*save;
	char		*line;
	int			i;
	int			j;
	int			ret;

	i = 0;
	j = 0;
	ret = 0;
	save = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); 
	while (j == 0)
	{
		if (!over)
			over = calloc(1, 1);
		buf = ft_memset(buf, 0, BUFFER_SIZE);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			return (line);
		while (over[i])
		{
			if (over[i] == '\n')
			{	
				save = ft_substr(over, 0, i + 1);
				over = ft_substr(over, i + 1, BUFFER_SIZE - (i));
				line = ft_strjoin(line, save);
				j = 1;
			}
			else if (over[i + 1] == '\0' && j == 0)
			{
				save = ft_substr(over, 0, i + 1);
				line = ft_strjoin(line, save);
			}
			i++;
		}
		over = ft_memset(over, 0, BUFFER_SIZE + 1);
		i = 0;
		while (buf[i])
		{
			if (buf[i] == '\n')
			{	
				save = ft_substr(buf, 0, i + 1);
				over = ft_substr(buf, i + 1, BUFFER_SIZE - (i));
				line = ft_strjoin(line, save);
				j = 1;
			}
			else if (buf[i + 1] == '\0' && j == 0)
			{
				save = ft_substr(buf, 0, i + 1);
				line = ft_strjoin(line, save);
			}
			i++;
		}
		i = 0;
	}
	return (line);
}
