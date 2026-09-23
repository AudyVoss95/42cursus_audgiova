/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audgiova <audgiova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:27:42 by audgiova          #+#    #+#             */
/*   Updated: 2026/09/21 21:59:39 by audgiova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *storage)
{
	char	*buffer;
	int		len;
	int		i;

	if (!storage || !storage[0])
		return (NULL);
	len = 0;
	while (storage[len] && storage[len] != '\n')
		len++;
	if (storage[len] == '\n')
		len++;
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buffer[i] = storage[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_clean_storage(char *storage)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\0')
	{
		free(storage);
		return (NULL);
	}
	i++;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!new_str)
	{
		free(storage);
		return (NULL);
	}
	j = 0;
	while (storage[i])
		new_str[j++] = storage[i++];
	new_str[j] = '\0';
	free(storage);
	return (new_str);
}

char	*read_and_store(int fd, char *storage)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr(storage, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (storage)
				free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	storage = read_and_store(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_extract_line(storage);
	storage = (char *)ft_clean_storage(storage);
	return (line);
}
