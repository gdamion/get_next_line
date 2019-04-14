/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:34:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/01/14 12:53:37 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	gol_ops_one(char **obj, char **tmp)
{
	free(*obj);
	*obj = *tmp;
}

static void	gol_ops_two(int *i, char **content)
{
	while ((*content)[*i] != '\0')
	{
		if ((*content)[*i] == '\n')
			break ;
		(*i)++;
	}
}

static int	get_one_line(char **line, const int fd, char **c, int *e)
{
	char		buf[BUFF_SIZE + 1];
	int			rd;
	int			i;
	char		*tmp;

	ft_bzero(buf, BUFF_SIZE + 1);
	rd = read(fd, buf, BUFF_SIZE);
	if (rd == -1 || !(tmp = ft_strjoin(*c, buf)))
		return (-1);
	gol_ops_one(c, &tmp);
	i = *e + 1;
	if (((*e == -1 && (*c)[i] == '\0')) || (*e != -1 && (*c)[*e] == '\0'))
		return (0);
	gol_ops_two(&i, c);
	if (rd == 0 && (i == *e + 1) && (*c)[i] == '\0')
		return (0);
	if (!(tmp = ft_strsub(*c, *e + 1, i - *e - 1)))
		return (-1);
	gol_ops_one(line, &tmp);
	if ((*c)[i] == '\n' || ((*c)[i] == '\0' && (rd == 0 || rd < BUFF_SIZE)))
	{
		*e = i;
		return (1);
	}
	return (get_one_line(line, fd, c, e));
}

int			get_next_line(const int fd, char **line)
{
	static t_files	files[FD_STORE_SIZE];

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(files[fd].content))
	{
		if (!(files[fd].content = ft_strnew(0)))
			return (-1);
		files[fd].endl = -1;
	}
	return (get_one_line(line, fd, &files[fd].content, &files[fd].endl));
}

// static int	get_one_line(char **line, const int fd, char **c, int *e)
// {
// 	char		buf[BUFF_SIZE + 1];
// 	int			rd;
// 	int			i;
// 	char		*tmp;

// 	ft_bzero(buf, BUFF_SIZE + 1);
// 	rd = read(fd, buf, BUFF_SIZE);
// 	if (rd == -1 || !(tmp = ft_strjoin(*c, buf)))
// 		return (-1);
// 	//printf("buf = %s|\n", buf);
// 	//printf("rd = %d, endl = %d|\n", rd, *e);
// 	gol_ops_one(c, &tmp);
// 	// if (rd == 0 && (*e == -1 || (*e != -1 && (*c)[*e] == '\0')))
// 	// 	return (0);
// 	i = *e + 1;
// 	gol_ops_two(&i, c);
// 	if (rd == 0 && i == *e + 1)
// 		return (0);
// 	//printf("content = %s|\n", *c);
// 	if ((*c)[i] == '\n' || ((*c)[i] == '\0' && rd < BUFF_SIZE))
// 	{
// 		if (!(tmp = ft_strsub(*c, *e + 1, i - *e - 1)))
// 			return (-1);
// 		gol_ops_one(line, &tmp);
// 		*e = i;
// 		//printf("new_endl = %d|\n", *e);
// 		return (1);
// 	}
// 	return (get_one_line(line, fd, c, e));
// }

