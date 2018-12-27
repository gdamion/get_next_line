#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.c"

int	main (int argc, char **argv)
{
	int fd;
	char *line;

	fd = open("testfile", O_RDONLY);
	printf("%d\n\n", get_1_line_v2((const int)fd, &line));
	printf("%s", line);
	close(fd);
	return (0);
}
