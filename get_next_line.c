/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:19:17 by gdamion-          #+#    #+#             */
/*   Updated: 2019/01/09 19:04:39 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read, malloc, free - allowed!

#include "get_next_line.h"

/*
int		get_next_line(const int fd, char **line)
{
	static int add;
	int i;
	int	rd;
	int	not1st;

	if (fd == -1 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);
	i = 0;
	not1st = 0;
	if (*line)
{
	while (*(line[i])) //считаем количество уже записанных символов
		i++;
}
	if (i) //проверяем, было ли что-то в line до запуска функции, чтобы выставить '\n'
		not1st = 1;
	if (add)
		not1st = 0;
	add = 0;
	if (!(*(line + i) = (char*)malloc(BUFF_SIZE + not1st))) //выделяем память под буфер
		return (-1);
	if (not1st) //ставим '\n', если строка не первая
		*(line[i]) = '\n';
	rd = read(fd, *(line + i + not1st), BUFF_SIZE); //читаем файл размера буфера
	if (rd == -1)
		return (-1);
	else if (rd == 0)
		return (0);
	else if (rd < BUFF_SIZE)
		return (1);
	else //строка равна буферу или длиннее буфера, входим в рекурсию чтобы дописать ее 
	{
		add = 1;
		get_next_line(fd, line);
		return (1);
	}
}
*/
/*
int		get_1_line(const int fd, char **line)
{
	static int add;
	int	rd;
	int i;
	char buf[BUFF_SIZE + 1];
	char *point;

	i = 0;
	if (fd == -1 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);
	point = *line + add;
	if (!(point = (char*)malloc(BUFF_SIZE))) //выделяем память под буфер
		return (-1);
	rd = read(fd, point, BUFF_SIZE); //читаем файл размера буфера
	if (rd == -1)
		return (-1);
	else if (rd == 0 || rd < BUFF_SIZE) //прочитано все
		return (0);
	else if (rd == BUFF_SIZE) //строка равна буферу или длиннее буфера, входим в рекурсию чтобы дописать ее 
	{
		add += rd;
		if (get_1_line(fd, line) == 0)
			return (0);
		while (i < rd)
		{
			if (*(line[i]) != '\n')
				return (1);
			i++;
		}
		return (get_1_line(fd, line));
	}
}
*/

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

int	get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int	rd;
	int n;

	n = 1;
	if (fd == -1 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);
	if (!(*line))
	{
		*line = (char*)malloc(1);
		**line = '\0';
	}
	rd = read(fd, buf, BUFF_SIZE); //читаем
	buf[BUFF_SIZE] = '\0'; //закупориваем буфер терминатором
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
		*line = ft_strjoin_mod(*line, buf, &n);
		if (n)
			return (1);
		else
			return (get_next_line(fd, line));
	}
	printf("PASSED tough PLACE 2\n\n");
	return (-1);
}
