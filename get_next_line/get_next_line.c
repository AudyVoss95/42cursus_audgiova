/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:27:42 by audgiova          #+#    #+#             */
/*   Updated: 2026/08/21 16:02:22 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *storage)
{
	char	*buffer;
	char	*temp;
	int		len;
	int		i;

	if (!storage || !storage[0])
		return (NULL);
	temp = (char *)storage;
	len = 0;
	while (storage[len] && storage[len] != '\n')
	{
		len++;
	}
	if (storage[len] == '\n')
		buffer = (char *)malloc(sizeof(char) * (len + 2));
	else
		buffer = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (storage[i])
	{
		buffer[i] = storage[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

void	ft_clean_storage(char *storage)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		i++;
	}
	if (storage[i] == '\0')
		free(storage);
		return (NULL);
	j = 0;
	while (storage[i] && storage[i] != '\n')
	{
		new_str[j] = storage[i];
		j++;
		i++;
	}
	free(storage);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	*storage;
	size_t	bytes_read;
	char	*buffer;

	while (!ft_strchr(storage, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(bytes_read);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	return (storage);
}
