/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:59:33 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/14 20:56:15 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!little[0])
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && !little[j] && (i + j) < len)
		{
			j++;
		}
		if (little[j])
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
