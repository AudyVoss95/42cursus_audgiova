/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 19:39:58 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/14 19:58:50 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	lenght_s;
	size_t	i;

	lenght_s = ft_strlen(s);
	if (start > lenght_s)
	{
		return ((char *) ft_calloc(1, sizeof(char)));
	}
	if (lenght_s - start < len)
	{
		len = lenght_s - start;
	}
	sub_string = malloc((len + 1) * sizeof(char));
	if (sub_string == NULL)
	{
		return (NULL);
	}
	i = -1;
	while (s[++i + start] & (i < len))
	{
		sub_string[i] = s[i + start];
	}
	sub_string[len] = '\0';
	return (sub_string);
}
