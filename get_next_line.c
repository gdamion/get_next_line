/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:19:17 by gdamion-          #+#    #+#             */
/*   Updated: 2019/01/11 14:04:10 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read, malloc, free - allowed!

#include "get_next_line.h"

/*
// pick 1-st line. WORKING!!!
int		get_one_line(char **line, const int fd, char *content, size_t *endl)
{
	char	buf[BUFF_SIZE + 1];
	int	rd;
	int i;
	static t_list files[FD_STORE_SIZE];

	if (fd < 0 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);

	ALLOC_MEM(*line, char*, 1);
	**line = '\0';

	if (!content)
	{
		ALLOC_MEM(content, char*, 1);
		*content = '\0';
		*endl = 0;
	}
	ft_bzero(buf, BUFF_SIZE + 1); //заполняем буфер терминаторами
	rd = read(fd, buf, BUFF_SIZE); //читаем
	printf("\nread: %d\n", rd);
	printf("buf:\n%s\n\n", buf);
	if (rd == -1 || !(content = ft_strjoin(content, buf))) //ошибка чтения и ошибка объединения
		return (-1);
	printf("content:\n%s\n\n", content);
	i = *endl;
	while (content[i] != '\0')
	{
		if (content[i] == '\n')
			break;
		i++;
	}
	//strsub here!
	*line = ft_strsub(content, *endl, i - *endl);
	printf("line:\n%s\n\n", *line);
	if (content[i] == '\n')
	{
		*endl = i;
		return (1);
	}
	if (rd == 0 || rd < BUFF_SIZE)
		return (0);
	else
		return (get_one_line(line, fd, content, endl));
}
*/

int		get_one_line(char **line, const int fd, char **content, size_t *endl)
{
	char	buf[BUFF_SIZE + 1];
	int	rd;
	int i;

	ft_bzero(buf, BUFF_SIZE + 1); //заполняем буфер терминаторами
	rd = read(fd, buf, BUFF_SIZE); //читаем
	if (rd == -1 || !(*content = ft_strjoin(*content, buf))) //ошибка чтения и ошибка объединения
		return (-1);
	i = *endl;
	while ((*content)[i] != '\0')
	{
		if ((*content)[i] == '\n')
			break;
		i++;
	}
	*line = ft_strsub(*content, *endl, i - *endl);
	if ((*content)[i] == '\n')
	{
		*endl = i + 1;
		return (1);
	}
	if (rd == 0 || rd < BUFF_SIZE)
		return (0);
	else
		return (get_one_line(line, fd, content, endl));
}
//25 strings !!!!!!

int		get_next_line(const int fd, char **line)
{
	static t_files files[FD_STORE_SIZE];
	int res;

	if (fd < 0 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);
	ALLOC_MEM(*line, char*, 1);
	**line = '\0';
	if (!(files[fd].content))
	{
		ALLOC_MEM(files[fd].content, char*, 1);
		*files[fd].content = '\0';
		files[fd].content_size = 0;
	}
	res = get_one_line(line, fd, &files[fd].content, &files[fd].content_size);
	return (res);
}
