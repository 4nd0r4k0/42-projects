/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:35:01 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 12:55:25 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_pb(t_list *l_begin, char *str, int end)
{
	t_list_node	*new_node;

	new_node = (t_list_node *)ft_alloc(sizeof(t_list_node));
	if (!new_node)
	{
		ft_clean(l_begin, 1);
		return ;
	}
	new_node->str = str;
	new_node->end = end;
	new_node->next = NULL;
	if (!(l_begin->head))
	{
		l_begin->head = new_node;
		l_begin->tail = new_node;
	}
	else
	{
		l_begin->tail->next = new_node;
		l_begin->tail = new_node;
	}
}

char	*ft_join(t_list *l_begin)
{
	int			total_len;
	t_list_node	*curr;
	int			check;
	int			len;
	char		*res;

	total_len = ft_strs_size(l_begin->head);
	res = (char *)ft_alloc((total_len + 1) * sizeof(char));
	if (!res)
		return (ft_clean(l_begin, 1));
	res[total_len] = '\0';
	curr = l_begin->head;
	check = 0;
	total_len = 0;
	while (curr && !check)
	{
		len = -1;
		while (curr->str[++len] != '\0')
			res[total_len + len] = curr->str[len];
		total_len += len;
		check |= curr->end;
		curr = curr->next;
	}
	ft_clean(l_begin, 0);
	return (res);
}

char	*ft_sub(char *str, int length)
{
	char	*ans;
	int		idx;

	ans = (char *)ft_alloc((length + 1) * sizeof(char));
	if (ans)
	{
		idx = -1;
		ans[length] = '\0';
		while (++idx < length)
			ans[idx] = str[idx];
	}
	return (ans);
}

int	ft_strs_size(t_list_node *curr)
{
	int	total_len;
	int	check;
	int	len;

	check = 0;
	total_len = 0;
	while (curr && !check)
	{
		len = 0;
		while (curr->str[len] != '\0')
			len++;
		total_len += len;
		check |= curr->end;
		curr = curr->next;
	}
	return (total_len);
}

char	*ft_clean(t_list *l_begin, int del_all)
{
	t_list_node	*nxt_ptr;
	t_list_node	*curr;
	int			check;

	check = 0;
	curr = l_begin->head;
	while (curr && (!check || del_all))
	{
		nxt_ptr = curr->next;
		check |= curr->end;
		free(curr->str);
		free(curr);
		curr = nxt_ptr;
	}
	l_begin->head = curr;
	l_begin->end_count -= (check || !curr);
	return (NULL);
}
