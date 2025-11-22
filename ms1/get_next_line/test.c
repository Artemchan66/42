
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 128
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{

	char 	buf[BUFFER_SIZE];
	int		bytes_read;
	int i;
	char *line;
	static int end;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (end)
		i = end;
	i = 0 + end;
	line = malloc(sizeof(char) * BUFFER_SIZE);
	while (buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	end = i;
	return line;
}

int	main()
{
	int fd = open("aboba.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return 0;
}

