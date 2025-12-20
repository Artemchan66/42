#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
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

char	*get_next_line(int fd)
{
	//string for reading data from fd
	//will be freed when we'll find newline
	char	reading_buffer[BUFFER_SIZE];	
	//static pointer to string in which we will store everything we read from fd
	static char *character_storage;
	//pointer to string that we want to output
	char	*output_line;
	//amout of bytes we get from reading a fd
	int		bytes_from_read;
	//reading_buffer iterator
	int		i;
	//if newline found - 1, not - 0
	int		is_newline_found;

	printf("%d", 1);
	//populating reading_buffer with character from fd
	bytes_from_read = read(fd, reading_buffer, BUFFER_SIZE);
	//file is empty - returning NULL
	if (bytes_from_read == 0)
		return NULL;

	bytes_from_read = 1;

	printf("%d", 1);

	//reading all data from fd into static character_storage
	//if we find a new line, mark it and wirte the remaining buffer_size values
	is_newline_found = 0;
	while(is_newline_found == 0)
	{
		character_storage = ft_strjoin(character_storage, reading_buffer);

		if (ft_strchr(reading_buffer, '\n'))
			is_newline_found = 1;
		else
		{	
			bytes_from_read = read(fd, reading_buffer, BUFFER_SIZE);
		}
	}
	i = 0;
	while (character_storage[i] != '\n')
	{
		output_line[i] = character_storage[i];
		i++;
	}

	return output_line;
}

int	main()
{
	int fd = open("aboba.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
}

