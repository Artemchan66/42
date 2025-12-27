#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h> //read();
#include <stdio.h> //printf();
#include <fcntl.h> //open();
#include <stdlib.h> //malloc();

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_b;
	const unsigned char	*src_b;

	dest_b = dest;
	src_b = src;
	while (n > 0)
	{
		*dest_b = *src_b;
		dest_b++;
		src_b++;
		n--;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	char	*ret;

	len = ft_strlen(s) + 1;
	dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	ret = dup;
	while (*s)
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}

char *read_from_buffer(int fd, int *is_newline_found, char *character_storage)
{
	char	reading_buffer[BUFFER_SIZE + 1];
	int		bytes_from_read;

	bytes_from_read = read(fd, reading_buffer, BUFFER_SIZE);
	if (bytes_from_read < 0)
		return NULL;
	if (bytes_from_read == 0)
	{
		*is_newline_found = 1;
		if (!character_storage || character_storage[0] == '\0')
			return NULL;
		else
			return character_storage;
	}
	reading_buffer[bytes_from_read] = '\0';
	character_storage = ft_strjoin(character_storage, reading_buffer);
	if (ft_strchr(reading_buffer, '\n'))
		*is_newline_found = 1;
	return character_storage;
}

char *get_output_line(char *character_storage, int *output_line_size)
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
	output_line[j++] = '\0';
	*output_line_size = i;
	return output_line;
}

void update_character_storage(char **character_storage, int output_line_size)
{
	size_t remaining_len = ft_strlen(*character_storage + output_line_size);
	char *buff_character_storage = malloc(remaining_len + 1);
	if (!buff_character_storage)
		return NULL;
	ft_memcpy(buff_character_storage, *character_storage + output_line_size, remaining_len);
	buff_character_storage[remaining_len] = '\0';
	free(*character_storage);
	*character_storage = buff_character_storage;
}

char	*get_next_line(int fd)
{
	char	reading_buffer[BUFFER_SIZE + 1];
	static char *character_storage;
	char	*output_line;
	int		output_line_size;
	int		is_newline_found;

	is_newline_found = 0;
	while(is_newline_found == 0)
	{
		character_storage = read_from_buffer(fd, &is_newline_found, character_storage);
		if (!character_storage)
			return NULL;
	}
	output_line_size = 0;
	output_line = get_output_line(character_storage, &output_line_size);
	update_character_storage(&character_storage, output_line_size);
	return output_line;
}

int	main()
{
	int fd = open("aboba.txt", O_RDONLY);
	
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

