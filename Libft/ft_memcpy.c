/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:53:22 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/11 17:27:46 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pointer_dest;
	const unsigned char	*pointer_src;

	pointer_dest = (unsigned char *)dest;
	pointer_src = (const unsigned char *)src;
	if (!dest && !src)
	{
		return (dest);
	}
	while (n > 0)
	{
		pointer_dest[n] = pointer_src[n];
		n--;
	}
	return (dest);
}
