/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:59:33 by audgiova          #+#    #+#             */
/*   Updated: 2026/06/10 15:26:46 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char    *ft_strnstr(const char *big, const char *little, size_t len);
/*locates the first	occurrence of the  null-terminated  string little in the string big, where not more than len characters are	searched.  Characters that appear after	a `\0' character  are not  searched.
Localiza a primeira ocorrência da string little dentro da string big, dentro do limite de len em big.
Retorno
Se little for vazio, todo o valor de big é retornado, se não tiver ocorrência de little em big é retornado NULL, caso contrário retorna um ponteiro para o primeiro caractere da primeira ocorrência em big
       If little is an empty string, big is returned; if little	occurs nowhere
       in big, NULL is returned; otherwise a pointer to	the first character of
       the first occurrence of little is returned.*/

char    *ft_strnstr(const char *big, const char *little, size_t len)
{
    int i;
    int j;
    
    if(little[0])
    {
        return(big);
    }
    i = 0;
    while(big[i])
    { 
        j = 0;
        while(big[i+j] == little[j] && little[j] && i < len)
        {
            j++;
        }
        if(little[j])
        {
            return (&big[i]);
        }
      i++; 
    }
    return (NULL);
}