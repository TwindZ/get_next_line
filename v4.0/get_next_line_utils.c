/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:15:25 by emlamoth          #+#    #+#             */
/*   Updated: 2023/02/02 14:39:52 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	unsigned char		*str;

	str = (unsigned char *)s;
	i = 0;
	if (!s)
		return ;
	while (i < n)
		str[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (malloc(count * size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoin(char *stack, char *buf)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*newstack;

	lens1 = ft_strlen(stack);
	lens2 = ft_strlen(buf);
	newstack = ft_calloc(lens1 + lens2 + 1, (sizeof(char)));
	if (!newstack)
		return (NULL);
	ft_memcpy(newstack, stack, lens1);
	ft_memcpy(newstack + lens1, buf, lens2);
	free(stack);
	return (newstack);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	int				i;
	unsigned char	*source;
	unsigned char	*dest;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	i = 0;
	if (src == NULL || dst == NULL)
		return (dst);
	while (n--)
	{
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

//--------------------------------------------------------------------//
