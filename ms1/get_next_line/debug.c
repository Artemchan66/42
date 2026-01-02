#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd;
	char *line;
	char *filename;

	filename = "aboba.txt";
	fd = open(filename, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return 0;
}
