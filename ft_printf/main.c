/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:28:10 by audgiova          #+#    #+#             */
/*   Updated: 2026/07/16 16:30:40 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"

int	main(void)
{
    int	len_orig;
    int	len_mine;

    printf("=== TESTES FT_PRINTF vs PRINTF ===\n\n");
    printf("--- Teste %%c ---\n");
    len_orig = printf("Original: [%c] [%c]\n", 'A', '\0');
    len_mine = ft_printf("Meu    : [%c] [%c]\n", 'A', '\0');
    printf("Retornos -> Original: %d | Meu: %d\n\n", len_orig, len_mine);
    printf("--- Teste %%s ---\n");
    len_orig = printf("Original: [%s] [%s]\n", "Ola Mundo", (char *)NULL);
    len_mine = ft_printf("Meu    : [%s] [%s]\n", "Ola Mundo", (char *)NULL);
    printf("Retornos -> Original: %d | Meu: %d\n\n", len_orig, len_mine);
    printf("--- Teste %%d e %%i ---\n");
    len_orig = printf("Original: [%d] [%i] [%d]\n", 42, -42, 0);
    len_mine = ft_printf("Meu    : [%d] [%i] [%d]\n", 42, -42, 0);
    printf("Retornos -> Original: %d | Meu: %d\n\n", len_orig, len_mine);
    printf("--- Teste %%u ---\n");
    len_orig = printf("Original: [%u] [%u]\n", 3000000000U, 0);
    len_mine = ft_printf("Meu    : [%u] [%u]\n", 3000000000U, 0);
    printf("Retornos -> Original: %d | Meu: %d\n\n", len_orig, len_mine);
    printf("--- Teste %%x e %%X ---\n");
    len_orig = printf("Original: [%x] [%X]\n", 255, 3735928559U);
    len_mine = ft_printf("Meu    : [%x] [%X]\n", 255, 3735928559U);
    printf("Retornos -> Original: %d | Meu: %d\n\n", len_orig, len_mine);
    printf("--- Teste %%p ---\n");
    int n = 42;
    len_orig = printf("Original: [%p] [%p]\n", &n, NULL);
    len_mine = ft_printf("Meu    : [%p] [%p]\n", &n, NULL);
    printf("Retornos -> Original: %d | Meu: %d\n\n", len_orig, len_mine);
    printf("--- Teste %%%%\n");
    len_orig = printf("Original: [%%] [%%%%]\n");
    len_mine = ft_printf("Meu    : [%%] [%%%%]\n");
    printf("Retornos -> Original: %d | Meu: %d\n\n", len_orig, len_mine);
    return (0);
}
