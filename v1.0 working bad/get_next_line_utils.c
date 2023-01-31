/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:15:25 by emlamoth          #+#    #+#             */
/*   Updated: 2023/01/25 16:26:46 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*newstr;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = (char *)malloc(lens1 + lens2 + 1 * (sizeof(char)));
	if (!newstr)
		return (NULL);
	ft_memcpy(newstr, s1, lens1);
	ft_memcpy(newstr + lens1, s2, lens2);
	newstr[lens1 + lens2] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			size;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	new = malloc((len + 1) * (sizeof(char)));
	if (!new || !s)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	srclen;	

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	i = 0;
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize < srclen)
		dst[dstsize - 1] = '\0';
	else if (dstsize != 0)
		dst[i] = '\0';
	return (srclen);
}

char	*ft_strdup(const char *s)
{
	void	*str;

	str = malloc((sizeof(char)) * ft_strlen(s) + 1);
	str = ft_memcpy(str, s, ft_strlen(s) + 1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (malloc(count * size));
	if (!a)
		return (NULL);
	ft_memset(a, 0, count * size);
	return (a);
}

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned int		i;
	unsigned char		*str;

	str = (unsigned char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (i < len)
		str[i++] = c;
	return (str);
}
