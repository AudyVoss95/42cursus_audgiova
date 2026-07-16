/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:04:11 by audgiova          #+#    #+#             */
/*   Updated: 2026/07/15 16:32:01 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_conversion(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
	{
		count += ft_putstr(va_arg(args, char *));
	}
	else if (c == 'x')
	{
		count += ft_puthexalow(va_arg(args, unsigned int));
	}
	else if (c == 'X')
	{
		count += ft_puthexaupper(va_arg(args, unsigned int));
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_check_conversion(format[i], args);
		}
		count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}
