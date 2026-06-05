/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 18:06:39 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/05 18:06:41 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dest, const void *src, int n);

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char *ptr_dest;
	const unsigned char *ptr_src;
	int i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	i = 0;
	if(!dest && !src)
	{
		return (ptr_dest);
	}

	if(dest > src)
	{
		while (n > 0)
		{
			ptr_dest[n] = ptr_src[n];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return(dest);


}
