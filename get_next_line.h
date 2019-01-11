/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:20:04 by gdamion-          #+#    #+#             */
/*   Updated: 2019/01/11 14:00:29 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 200
# define FD_STORE_SIZE 200
# define ALLOC_MEM(x, y, z)\
			x=(y)malloc(z);\
			if (!x)\
				return (-1)

# include "libft/libft.h"

typedef struct		s_files
{
	char			*content;
	size_t			content_size;
}					t_files;

int		get_next_line(const int fd, char **line);
int		get_one_line(char **line, const int fd, char **content, size_t *endl);
//char	*ft_strjoin_mod(char *s1, char  *s2, int *n);

#endif
