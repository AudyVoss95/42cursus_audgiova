/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:10:38 by audgiova          #+#    #+#             */
/*   Updated: 2026/07/16 16:22:15 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr(void *ptr)
{
	int		counter;
	char	*prefix;

	counter = 0;
	if (!ptr)
		counter += ft_putstr("(nil)");
	else
	{
		prefix = "0x";
		counter += ft_putstr(prefix);
		counter += ft_puthex((unsigned long long) ptr, "0123456789abcdef");
	}
	return (counter);
}
