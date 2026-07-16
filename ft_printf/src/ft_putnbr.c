/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 10:53:04 by audgiova          #+#    #+#             */
/*   Updated: 2026/07/16 15:06:14 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_putstr(str);
	free(str);
	return (len);
}

int	ft_putuint(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
		count += ft_putchar(nb + '0');
	return (count);
}
