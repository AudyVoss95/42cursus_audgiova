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

void	*ft_memset(void *s, int c, int n);

void	*ft_memset(void *s, int c, int n)
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