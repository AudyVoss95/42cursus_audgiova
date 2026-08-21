/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:33:06 by audgiova          #+#    #+#             */
/*   Updated: 2026/08/21 15:09:09 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen((char *)s))
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pointer_dest;
	const unsigned char	*pointer_src;
	size_t				i;

	pointer_dest = (unsigned char *)dest;
	pointer_src = (const unsigned char *)src;
	if (!dest && !src)
	{
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		pointer_dest[i] = pointer_src[i];
		i++;
	}
	pointer_dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*buffer;

	if (!s2)
		return (NULL);
	if (!s1)
		len_s1 = 0;
	else
		len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	buffer = (char *)malloc(len_s1 + len_s2 + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, len_s1);
	ft_memcpy(buffer + len_s1, s2, len_s2);
	buffer[len_s1 + len_s2] = '\0';
	free((void *)s1);
	return (buffer);
}
