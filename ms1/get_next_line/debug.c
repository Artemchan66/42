#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd = open("aboba.tx", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", get_next_line(fd));
	free(line);

	return 0;
}
