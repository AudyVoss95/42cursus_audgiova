/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 16:25:00 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/05 16:25:09 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint (int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_strlen(char *str);
void	*ft_memset(void *s, int c, int n);
void	ft_bzero(void *s, int n);
void	*memcpy(void *dest, const void *src, int n);
#endif // DEBUG
