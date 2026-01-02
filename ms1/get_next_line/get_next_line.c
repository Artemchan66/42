/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabdull <arabdull@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:30 by arabdull          #+#    #+#             */
/*   Updated: 2026/01/02 13:03:59 by arabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_chunk_from_file(int fd)
{
	char	*chunk;
	int		bytes_from_read;

	chunk = malloc(BUFFER_SIZE + 1);
	if (!chunk)
		return (NULL);
	bytes_from_read = read(fd, chunk, BUFFER_SIZE);
	if (bytes_from_read < 0)
	{
		free(chunk);
		return (NULL);
	}
	chunk[bytes_from_read] = '\0';
	if (bytes_from_read == 0)
	{
		free(chunk);
		return (NULL);
	}
	return (chunk);
}

static char	*populate_data_storage(int fd, char *data_storage)
{
	char	*tmp_data_storage;
	char	*chunk;

	chunk = read_chunk_from_file(fd);
	if (!chunk)
		return (data_storage);
	if (!data_storage)
		return (chunk);
	tmp_data_storage = data_storage;
	data_storage = ft_strjoin(tmp_data_storage, chunk);
	if (!data_storage)
	{
		free(tmp_data_storage);
		return (NULL);
	}
	free(tmp_data_storage);
	free(chunk);
	return (data_storage);
}

static char	*get_output_line(char *data_storage, int *output_line_size)
{
	char	*output_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data_storage[i] != '\0' && data_storage[i] != '\n')
		i++;
	if (data_storage[i] == '\n')
		i++;
	output_line = malloc(i + 1);
	if (!output_line)
		return (NULL);
	while (j < i)
	{
		output_line[j] = data_storage[j];
		j++;
	}
	output_line[j] = '\0';
	*output_line_size = i;
	return (output_line);
}

static int	shrink_data_storage(char **data_storage, int output_line_size)
{
	size_t	shrink_data_storage_len;
	char	*tmp_data_storage;

	shrink_data_storage_len = ft_strlen(*data_storage + output_line_size);
	if (shrink_data_storage_len == 0)
	{
		free(*data_storage);
		*data_storage = NULL;
		return (1);
	}
	tmp_data_storage = malloc(shrink_data_storage_len + 1);
	if (!tmp_data_storage)
	{
		free(*data_storage);
		*data_storage = NULL;
		return (0);
	}
	ft_memcpy(tmp_data_storage, *data_storage + output_line_size,
		shrink_data_storage_len);
	tmp_data_storage[shrink_data_storage_len] = '\0';
	free(*data_storage);
	*data_storage = tmp_data_storage;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*data_storage;
	char		*data_storage_before_population;
	char		*output_line;
	int			output_line_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (data_storage == NULL || !ft_strchr(data_storage, '\n'))
	{
		data_storage_before_population = data_storage;
		data_storage = populate_data_storage(fd, data_storage);
		if (!data_storage || data_storage == data_storage_before_population)
			break ;
	}
	if (!data_storage)
		return (NULL);
	output_line = get_output_line(data_storage, &output_line_size);
	if (!shrink_data_storage(&data_storage, output_line_size))
	{
		free(output_line);
		return (NULL);
	}
	return (output_line);
}
