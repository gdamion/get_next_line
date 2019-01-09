#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
#include "get_next_line.c"

int	main (int argc, char **av)
{
	int fd;
	char *line;
	/*
	char *sumline;
	int a = 1;

printf ("tl1: %s\n", av[1]);
printf ("tl2: %s\n\n", av[2]);
sumline = ft_strjoin_mod (av[1], av[2], &a);
printf ("res of strjoinmod: %s", sumline);
*/
	fd = open("testfile", O_RDONLY);
	printf("\nGNL return:\n%d\n", get_next_line((const int)fd, &line));
	printf("line content: %s", line);
	close(fd);
	return (0);

}
