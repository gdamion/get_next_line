/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:19:17 by gdamion-          #+#    #+#             */
/*   Updated: 2019/01/13 11:51:08 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_one_line(char **line, const int fd,
						char **content, size_t *endl)
{
	char	buf[BUFF_SIZE + 1];
	int		rd;
	size_t	i;

	ft_bzero(buf, BUFF_SIZE + 1);
	rd = read(fd, buf, BUFF_SIZE);
	if (rd == -1 || !(*content = ft_strjoin(*content, buf)))
		return (-1);
	i = *endl + 1;
	while ((*content)[i] != '\0')
	{
		if ((*content)[i] == '\n')
			break ;
		i++;
	}
	*line = ft_strsub(*content, *endl + 1, i - *endl - 1);
	if (rd == 0 && i == *endl + 1 && (*content)[i] == '\0')
		return (0);
	else if ((*content)[i] == '\n' ||
			((*content)[i] == '\0' && (rd == 0 || rd < BUFF_SIZE)))
	{
		*endl = i;
		return (1);
	}
	return (get_one_line(line, fd, content, endl));
}

int			get_next_line(const int fd, char **line)
{
	static t_files	files[FD_STORE_SIZE];
	int				res;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (!(files[fd].content))
	{
		if (!(files[fd].content = ft_strnew(0)))
			return (-1);
		files[fd].endl = -1;
	}
	res = get_one_line(line, fd, &files[fd].content, &files[fd].endl);
	return (res);
}
