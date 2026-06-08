/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:13:56 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/05 17:13:58 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *pointer;

	pointer = (unsigned char *)s;
	while (n > 0)
	{
		pointer[n] = (unsigned char) c;	 
		n--;
	}
	return (pointer);
}