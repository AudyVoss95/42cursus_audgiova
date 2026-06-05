/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:53:22 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/05 17:53:24 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memcpy(void *dest, const void *src, int n);

void	*memcpy(void *dest, const void *src, int n)
{
	unsigned char *pointer_dest;
	const unsigned char *pointer_src;

	pointer_dest = (unsigned char *)dest;
	pointer_src = (const unsigned char *)src;

	while (n > 0)
	{
		pointer_dest[n] = pointer_src[n];
		n--;
	}
	return (dest);
}
