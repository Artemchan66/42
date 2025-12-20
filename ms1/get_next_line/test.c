
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 9
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	char 	buf[BUFFER_SIZE];
	int		bytes_read;
	int i = 0;
	char *line;
	static char statBuf[BUFFER_SIZE];

	//reading data from file desctiptor
	if (statBuf[0] == '\0')
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == 0)
			return NULL;
	}
	else
	{
		printf("%d\n", 1);
		int w = 0;
		while (statBuf[w] != '\0')
		{
			buf[w] = statBuf[w];
			w++;
		}
	}
	
	//allocating memory to fill data from file that we read
	line = malloc(sizeof(char) * BUFFER_SIZE);

	//populating allocated memory with data from file
	while(buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';

	if (i < bytes_read)
	{
		i++;
		int j = 0;
		while (i < bytes_read)
		{
			statBuf[j] = buf[i];
			j++;
			i++;
		}
		statBuf[j] = '\0';
	}
	else
	{
		statBuf[0] = '\0';
	}

	return line;
}

int	main()
{
	int fd = open("aboba.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return 0;
}

