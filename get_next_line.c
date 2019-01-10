/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:19:17 by gdamion-          #+#    #+#             */
/*   Updated: 2019/01/10 14:44:17 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read, malloc, free - allowed!

#include "get_next_line.h"

/*
char	*ft_strjoin_mod(char *s1, char  *s2, int *n)
{
	char	*s_new;
	size_t	i;
	size_t	j;

	if ((!s1 && !s2) || !(s_new = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s_new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		if (s2[j] == '\n')
			break;
		s_new[i] = s2[j];
		i++;
		j++;
	}
	if (s2[j] != '\n')
		*n = 0;
	s_new[i] = '\0';
	return (s_new);
}
*/
/*
// pick 1-st line. PROTOTYPE.
int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int	rd;
	int n;

	ft_bzero(buf, BUFF_SIZE + 1); //заполняем буфер терминаторами
	n = 1;
	if (fd < 0 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);
	if (!(*line))
	{
		*line = (char*)malloc(1);
		**line = '\0';
	}
	rd = read(fd, buf, BUFF_SIZE); //читаем
	printf("read: %d\n", rd);
	printf("buf: %s\n", buf);
	printf("line: %s\n", *line);
	if (rd == -1) //ошибка чтения
		return (-1);
	if (rd == 0 || rd < BUFF_SIZE) //прочитано все
		return (0);
	if (rd == BUFF_SIZE) //Записан весь буфер. Теперь проверяем, прошли ли мы конец строки или дошли до конца файла.
	//Нет? -> Читаем заново. Предварительно переписав буфер в line полностью		Да? -> return 1 or 0, переписав буфер до \n
	{
		printf("read==buf entered\n\n");
		if(!(*line = ft_strjoin_mod(*line, buf, &n)))
			return (-1);
		if (n)
			return (1);
		else
			return (get_next_line(fd, line));
	}
	printf("PASSED tough PLACE 2\n\n");
	return (-1);
}
*/

int		get_one_line(char **line, const int fd, char **content, size_t *endl)
{
	char	buf[BUFF_SIZE + 1];
	int	rd;
	int endl_loc = 0;
	int i = 0;
	int start;
	int len = 0;

	if (!(*endl))
		start = 0;
	ft_bzero(buf, BUFF_SIZE + 1); //заполняем буфер терминаторами
	if (!(*content))
	{
		ALLOC_MEM(*content, char*, 1);
		**content = '\0';
	}
	rd = read(fd, buf, BUFF_SIZE); //читаем
	printf("read: %d\n", rd);
	printf("buf:\n%s\n", buf);
	if (rd == -1 || !(*content = ft_strjoin(*content, buf))) //ошибка чтения и ошибка объединения
		return (-1);
	printf("line:\n%s\n", *content);
	while (*content)
	{
		if (*content[i] == '\n')
		{
			endl_loc++;
			if (endl_loc == *endl)
				start = i;
			else if (endl_loc == *endl + 1)
			{
				*line = ft_strsub(*content, start, len);
				*endl++;
				return (1);
			}
		}
		else if (endl_loc == *endl)
			len++;
		i++;
	}
	*line = ft_strsub(*content, start, len);
	if (endl_loc == *endl && (rd == 0 || rd < BUFF_SIZE))
		return (0);
	else
		return (get_one_line(line, fd, content, endl));
}

/*
int		get_next_line(const int fd, char **line)
{
	static t_list files[FD_STORE_SIZE];
	
	if (fd < 0 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);

	get_next_line(line, fd, &files[fd].content, &files[fd].content_size);
}
*/