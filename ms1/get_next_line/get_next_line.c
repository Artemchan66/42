/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:30 by arabdull          #+#    #+#             */
/*   Updated: 2025/12/28 15:40:21 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*read_from_buffer(int fd, char *character_storage)
{
	char	*reading_buffer;
	int		bytes_from_read;
	char	*tmp_character_storage;

	reading_buffer = malloc(BUFFER_SIZE + 1);
	if (!reading_buffer)
		return NULL;
	bytes_from_read = read(fd, reading_buffer, BUFFER_SIZE);
	if (bytes_from_read < 0)
	{
		free(reading_buffer);
		return NULL;
	}
	reading_buffer[bytes_from_read] = '\0';
	if (bytes_from_read == 0)
		return character_storage;
	if (!character_storage)
		return ft_strdup(reading_buffer);
	tmp_character_storage = character_storage;
	character_storage = ft_strjoin(tmp_character_storage, reading_buffer);
	free(tmp_character_storage);
	return (character_storage);
}

char	*get_output_line(char *character_storage, int *output_line_size)
{
	char	*output_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (character_storage[i] != '\0' && character_storage[i] != '\n')
		i++;
	if (character_storage[i] == '\n')
		i++;
	output_line = malloc(i + 1);
	if (!output_line)
		return NULL;
	while (j < i)
	{
		output_line[j] = character_storage[j];
		j++;
	}
	output_line[j] = '\0';
	*output_line_size = i;
	return output_line;
}

int	update_character_storage(char **character_storage, int output_line_size)
{
	size_t remaining_len = ft_strlen(*character_storage + output_line_size);
	if (remaining_len == 0)
	{
		free(*character_storage);
		*character_storage = NULL;
		return 1;
	}
	char *buff_character_storage = malloc(remaining_len + 1);
	if (!buff_character_storage)
		return (0);
	ft_memcpy(buff_character_storage, *character_storage + output_line_size, remaining_len);
	buff_character_storage[remaining_len] = '\0';
	free(*character_storage);
	*character_storage = buff_character_storage;
	return (1);
}

char	*get_next_line(int fd)
{
	static char *character_storage;
	char	*output_line;
	int		output_line_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	while(!character_storage || !ft_strchr(character_storage, '\n'))
	{
		char *prev = character_storage;
		character_storage = read_from_buffer(fd, character_storage);
		if (!character_storage || character_storage == prev)
			break;
	}
	if (!character_storage)
		return NULL;
	output_line = get_output_line(character_storage, &output_line_size);
	if(!update_character_storage(&character_storage, output_line_size))
	{
		free(output_line);
		return NULL;
	}
	return output_line;
}
