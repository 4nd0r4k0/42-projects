/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:34:47 by andorako          #+#    #+#             */
/*   Updated: 2024/03/28 09:34:49 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_checkb(char *buff, int bytes, t_list *lst, int fd)
{
	int				sz;
	unsigned char	*chars;

	free(buff);
	if (bytes < 0)
	{
		ft_cleanb(lst + fd, 1);
		sz = sizeof(t_list);
		chars = (unsigned char *)(lst + fd);
		while (--sz >= 0)
			chars[sz] = '\0';
	}
}

char	*get_next_line(int fd)
{
	int				s;
	int				bytes;
	char			*buff;
	static t_list	ns [N];

	if (fd < 0 || fd >= N || BUFFER_SIZE < 0 || ns[fd].end_count < 0)
		return ((char *)(long)((fd >= 0 && fd < N) && ft_cleanb(ns + fd, 1)));
	if (ns[fd].end_count > 0)
		return (ft_joinb(ns + fd));
	buff = (char *)ft_allocb(BUFFER_SIZE);
	if (!buff)
		return (ft_cleanb(ns + fd, 1));
	s = -1;
	while (s < 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		s = ft_next_startb(ns + fd, buff, bytes);
	}
	ft_checkb(buff, bytes, ns, fd);
	if (!(ns[fd].head) || bytes < 0)
		return (NULL);
	return (ft_joinb(ns + fd));
}

void	ft_pushb(t_list *l_begin, char *str, int length, int is_end)
{
	char	*subb;

	if (length < 0)
		return ;
	subb = ft_subb(str, length);
	if (!subb)
	{
		ft_cleanb(l_begin, 1);
		return ;
	}
	ft_push_backb(l_begin, subb, is_end);
	l_begin->end_count += is_end;
}

int	ft_next_startb(t_list *l_begin, char *buff, int bytes)
{
	int	start;
	int	idx;

	idx = 0;
	start = -1;
	while (idx < bytes)
	{
		if (buff[idx] == '\n')
		{
			ft_pushb(l_begin, buff + start + 1, idx - start, 1);
			start = idx;
		}
		idx++;
	}
	if (start + 1 < bytes)
		ft_pushb(l_begin, buff + start + 1, bytes - start - 1, 0);
	return (start);
}

void	*ft_allocb(int sz)
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
