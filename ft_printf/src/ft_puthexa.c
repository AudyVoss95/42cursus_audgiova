/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:24:18 by audgiova          #+#    #+#             */
/*   Updated: 2026/07/16 16:45:22 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long nb, char *base)
{
	int					count;
	unsigned long long	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nb >= base_len)
		count += ft_puthex((nb / base_len), base);
	count += ft_putchar(base[nb % base_len]);
	return (count);
}
