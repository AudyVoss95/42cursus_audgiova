/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 17:36:03 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/05 17:36:04 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_bzero(void *s, size_t n);


void	ft_bzero(void *s, size_t n)
{
	unsigned char *pointer;

	pointer = (unsigned char *)s;

	while (n > 0)
	{
		pointer[n] = '\0';
		n--;
	}
}