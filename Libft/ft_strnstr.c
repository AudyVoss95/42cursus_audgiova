/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:59:33 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/11 17:25:57 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	if (!little[0])
	{
		return (big);
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
