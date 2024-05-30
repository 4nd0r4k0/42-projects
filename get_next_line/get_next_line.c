/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:34:24 by andorako          #+#    #+#             */
/*   Updated: 2024/03/28 09:39:21 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_check(char *buff, int bytes, t_list *lst)
{
	int				sz;
	unsigned char	*chars;

	free(buff);
	if (bytes < 0)
	{
		ft_clean(lst, 1);
		sz = sizeof(t_list);
		chars = (unsigned char *)lst;
		while (--sz >= 0)
			chars[sz] = '\0';
	}
}

char	*get_next_line(int fd)
{
	int				s;
	int				bytes;
	char			*buff;
	static t_list	fd_node;

	if (fd < 0 || BUFFER_SIZE < 0 || fd_node.end_count < 0)
		return (ft_clean(&fd_node, 1));
	if (fd_node.end_count > 0)
		return (ft_join(&fd_node));
	buff = (char *)ft_alloc(BUFFER_SIZE + 1);
	if (!buff)
		return (ft_clean(&fd_node, 1));
	s = -1;
	while (s < 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		s = ft_next_start(&fd_node, buff, bytes);
	}
	ft_check(buff, bytes, &fd_node);
	if (!(fd_node.head) || bytes < 0)
		return (NULL);
	return (ft_join(&fd_node));
}

void	ft_push(t_list *l_begin, char *str, int length, int is_end)
{
	char	*sub;

	if (length < 0)
		return ;
	sub = ft_sub(str, length);
	if (!sub)
		ft_clean(l_begin, 1);
	else
	{
		ft_push_back(l_begin, sub, is_end);
		l_begin->end_count += is_end;
	}
}

int	ft_next_start(t_list *l_begin, char *buff, int bytes)
{
	int	start;
	int	idx;

	idx = 0;
	start = -1;
	while (idx < bytes)
	{
		if (buff[idx] == '\n')
		{
			ft_push(l_begin, buff + start + 1, idx - start, 1);
			start = idx;
		}
		idx++;
	}
	if (start + 1 < bytes)
		ft_push(l_begin, buff + start + 1, bytes - start - 1, 0);
	return (start);
}

void	*ft_alloc(int sz)
{
	int				idx;
	unsigned char	*buff;

	if (sz <= 0)
		return (NULL);
	buff = (unsigned char *)malloc(sz);
	if (buff)
	{
		idx = 0;
		while (idx < sz)
			buff[idx++] = '\0';
	}
	return ((void *)buff);
}
