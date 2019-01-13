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
int i = 1;
char *line1 = NULL;
char *line2 = NULL;

int fd1 = open("test1.txt", O_RDONLY);
int fd2 = open("test2.txt", O_RDONLY);
int gnl_out = 0;

printf("\nfd1 = %d\n", fd1);
printf("\nfd2 = %d\n", fd2);
while (i < 4)
{
	
	printf("\n____________________ITER %d ____________________\n", i);
	printf("\nFD1____________");
	gnl_out = get_next_line(fd1, &line1);
	printf("\nout = %d", gnl_out);
	printf("\nline=%s\n", line1);

	printf("\nFD2____________");
	gnl_out = get_next_line(fd2, &line2);
	printf("\nout = %d", gnl_out);
	printf("\nline=%s\n", line2);

	i++;
}

return (1);
/*
printf("\nSTEP 2\n\n");
gnl_out = get_next_line(fd, &line);
printf("\ngnl_out =%d\n", gnl_out);
printf("\nline =%s\n", line);
if (line != NULL || *line != '\0')
	printf("\nTI LOH! line =%s\n, a ne \\0 ili NULL \n", line);
*/
/*
	int fd_big = open("one_big_fat_line.txt", O_RDONLY);
	char*	s;
	get_next_line(fd_big, &s);
	printf("%s", s);
*/
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
	//line = NULL;
/*
	fd = open("one_big_fat_line.txt", O_RDONLY);
	printf("\n");
	printf("one_big_fat_line.txtn\n");
	printf("fd = %d\n\n", fd);
	printf("\nGNL return 1: %d\n\n", get_next_line(fd, &line));
	printf("%s", line);
	free(line);
	line = NULL;
	printf("\nGNL return 2: %d\n\n", get_next_line(fd, &line));
		free(line);
	line = NULL;
	printf("\nGNL return 3: %d\n\n", get_next_line(fd, &line));
		free(line);
	line = NULL;
	printf("\nGNL return 4: %d\n\n", get_next_line(fd, &line));
		free(line);
	line = NULL;
	printf("\nGNL return 5: %d\n\n", get_next_line(fd, &line));
		free(line);
	line = NULL;
	close(fd);
*/
/*
	fd = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	rd = read(fd, NULL, 10);
	printf("rd = %d\n\n", rd);
	close(fd);
	*/
/*
	printf("\n\n");
	printf("EOF\n\n");
	fd = open("gnl7_3.txt", O_RDONLY);
	printf("fd = %d\n\n", fd);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 1: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 2: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 3: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 4: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 5: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;

	printf("\n\n");
	printf("LINE FEED\n\n");
	fd = open("gnl3_3.txt", O_RDONLY);
	printf("fd = %d\n\n", fd);
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 1: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 2: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 3: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 4: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;
	printf("!!!!!!!!!!!!!!!!!!!!!!!!GNL RETURN 5: %d !!!!!!!!!!!!!!!!!!!!!!!!\n\n", get_next_line(fd, &line));
	free(line);
	line = NULL;

	close(fd);
	return (0);
	*/
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
