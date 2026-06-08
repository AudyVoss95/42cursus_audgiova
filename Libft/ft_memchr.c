/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:19:44 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/08 16:19:48 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	int					i;

	i = 0;
	ptr = (unsigned char *)s;
	while (*ptr && i < n)
	{
		if (*ptr == (char)c)
		{
			return ((void *)(ptr + i));
		}
		ptr++;
		i++;
	}
	return (NULL);
}
