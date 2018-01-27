/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:15:53 by dpogrebn          #+#    #+#             */
/*   Updated: 2017/12/14 17:15:54 by dpogrebn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_make_buf(t_gnl *new)
{
	char	*str;
	int		index;
	int		num;

	index = 0;
	num = new->ret;
	str = new->c;
	while (*str != '\n' && *str != '\0')
	{
		num--;
		str++;
	}
	str++;
	while (num > 1)
	{
		new->c[index] = *str;
		index++;
		str++;
		num--;
	}
	while (index < BUFF_SIZE)
	{
		new->c[index] = '\0';
		index++;
	}
}

static void		ft_lback(t_gnl **lst, t_gnl **work, int fd)
{
	t_gnl *new;
	t_gnl *elem;

	*work = (t_gnl *)malloc(sizeof(t_gnl));
	(*work)->c = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	ft_memset((*work)->c, '\0', ft_strlen((*work)->c));
	elem = *work;
	elem->fd = fd;
	new = *lst;
	elem->next = NULL;
	if ((*lst) && elem && lst)
	{
		while (new->next)
			new = new->next;
		new->next = elem;
	}
	if (*lst == NULL && elem != NULL && lst != NULL)
		*lst = elem;
}

static int		ft_make_str(t_gnl *new, char **line)
{
	int		len;

	if (new->ret == 0)
		return (0);
	if (new->ret != BUFF_SIZE && new->str == NULL)
	{
		*line = ft_strdup(new->c);
		ft_make_buf(new);
		return (1);
	}
	len = new->str - new->c;
	if (new->str != NULL && new->ret != BUFF_SIZE)
	{
		len = 0;
		while (new->c[len] != '\n' && new->c[len] != '\0')
			len++;
	}
	new->str2 = ft_strsub(new->c, 0, len);
	new->str1 = *line;
	*line = ft_strjoin(new->str1, new->str2);
	free(new->str1);
	free(new->str2);
	ft_make_buf(new);
	return (1);
}

static int		ft_iter(t_gnl **list, t_gnl **new, char **line, int fd)
{
	char	*str;

	while (new && (*new) && (*new)->fd != fd)
		(*new) = (*new)->next;
	if (!(*new))
	{
		ft_lback(list, new, fd);
		(*new)->ret = 1;
	}
	*line = (char *)malloc(sizeof(char));
	*line = ft_memset(*line, '\0', ft_strlen(*line));
	while (!((*new)->str = ft_strchr((*new)->c, '\n')) && (*new)->ret != 0)
	{
		str = *line;
		*line = ft_strjoin(str, (*new)->c);
		free(str);
		(*new)->ret = read(fd, (*new)->c, BUFF_SIZE);
		if ((*new)->ret < 0)
		{
			free(*line);
			return (0);
		}
		(*new)->c[(*new)->ret] = '\0';
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static	t_gnl	*list;
	t_gnl			*new;

	if (fd < 0 || BUFF_SIZE < 0)
		return (-1);
	if (!list)
	{
		list = (t_gnl *)malloc(sizeof(t_gnl));
		list->c = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		list->fd = fd;
		list->ret = 1;
		list->next = NULL;
	}
	new = list;
	if (!line || !ft_iter(&list, &new, line, fd))
		return (-1);
	if (ft_make_str(new, line) ||
		((!ft_make_str(new, line)) && (ft_strcmp(*line, ""))))
		return (1);
	free(*line);
	new->ret = 1;
	return (0);
}
