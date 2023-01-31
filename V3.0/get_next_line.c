/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:19:49 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/31 17:35:16 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(unsigned int fd, char *buf)
{
	int	ret;

	ret = 0;
	if (!buf)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (NULL);
	}
	if(buf[0] == '\0')
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0 || ret == -1)
		{	
			free(buf);
			return (NULL);
		}
	}
	return (buf);
}

char	*ft_split(char *buf, int i, char *temp)
{

	ft_memcpy(temp, buf, i + 2);
	ft_memcpy(buf, buf + i + 1, BUFFER_SIZE + 1 );
	buf[i + 1] = '\0';
	return (temp);
}

char	*ft_line(char *line, char *buf, int i)
{
	void	*temp;

	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
	{
		temp = calloc(i + 1, sizeof(char));
		if(!temp)
			return (NULL);
		ft_split(buf, i, temp);
	}
	else
		temp = buf;
	line = ft_strjoin(line, temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char static *buf;
	void		*line;
	
	line = calloc(1, 1);
		if(!line)
			return (NULL);
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (buf == NULL)
		return(NULL);	
	line = ft_line(line, buf, 0);
	return (line);
}
