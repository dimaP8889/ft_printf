/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:16:00 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/14 17:16:01 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include "./libft.h"
# include <fcntl.h>

# define BUFF_SIZE 100

typedef struct			s_gnl
{
	char				*c;
	char				*str;
	char				*str1;
	char				*str2;
	int					ret;
	int					fd;
	struct s_gnl		*next;
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif
