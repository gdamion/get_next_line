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
	int i=0;
	char *content;
	size_t endl;


	/*
	char *sumline;
	int a = 1;

	printf ("tl1: %s\n", av[1]);
	printf ("tl2: %s\n\n", av[2]);
	sumline = ft_strjoin_mod (av[1], av[2], &a);
	printf ("res of strjoinmod: %s", sumline);
	*/
/*
	//tests for reading 1-st line of file (get_one_line)
	fd = open("testfile", O_RDONLY);
	printf("\nSTART\n\n");
	printf("\n\nGNL return 1: %d\n\n", get_one_line(&line, (const int)fd, content, &endl));
	printf("\n\nGNL return 2: %d\n\n", get_one_line(&line, (const int)fd, content, &endl));
	printf("\n\nGNL return 3: %d\n\n", get_one_line(&line, (const int)fd, content, &endl));
	
	close(fd);
	return (0);
*/

	fd = open("testfile", O_RDONLY);
	printf("\nSTART\n\n");
	get_next_line(fd, &line);
	get_next_line(fd, &line);
	get_next_line(fd, &line);

	/*
	printf("\nGNL return 1: %d\n\n", get_next_line(fd, &line));
	printf("\n\nGNL return 2: %d\n\n", get_next_line(fd, &line));
	printf("\n\nGNL return 3: %d\n\n", get_next_line(fd, &line));
	*/
/*
	//tests fort ALLOC_MEM macro
	ALLOC_MEM(line, char*, 10);
	while (i < 9)
	{
		line[i] = i + 48;
		i++;
	}
	line[i] = '\0';
	printf("%s\n", line);
	return (1);
*/
}
