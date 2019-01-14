/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:20:04 by gdamion-          #+#    #+#             */
/*   Updated: 2019/01/14 11:18:23 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"

# define BUFF_SIZE 14
# define FD_STORE_SIZE 5000

typedef struct		s_files
{
	char			*content;
	int				endl;
}					t_files;

int					get_next_line(const int fd, char **line);

#endif
