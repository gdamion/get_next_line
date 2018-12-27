/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:19:17 by gdamion-          #+#    #+#             */
/*   Updated: 2018/12/27 19:53:33 by gdamion-         ###   ########.fr       */
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

int		get_1_line(const int fd, char **line)
{
	static int add;
	int	rd;
	int i;

	i = 0;
	if (fd == -1 || !line) //проверяем входящие значения на ошибку или отсутствие
		return (-1);
	if (!((*line + add) = (char*)malloc(BUFF_SIZE))) //выделяем память под буфер
		return (-1);
	rd = read(fd, *line + add, BUFF_SIZE); //читаем файл размера буфера
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
