/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:41:54 by andorako          #+#    #+#             */
/*   Updated: 2024/05/06 16:02:42 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_min_idx(t_stack *st, int ref)
{
	t_stack_node	*node;
	int				max_min_idx;
	int				max_min;
	int				idx;

	node = st->tail;
	max_min = -2147483648;
	max_min_idx = -1;
	idx = 0;
	while (node)
	{
		if (node->value <= ref && node->value >= max_min)
		{
			max_min = node->value;
			max_min_idx = idx;
		}
		idx++;
		node = node->prev;
	}
	return (max_min_idx);
}

int	ft_min_max_idx(t_stack *st, int ref)
{
	t_stack_node	*node;
	int				min_max_idx;
	int				min_max;
	int				idx;

	node = st->tail;
	min_max = 2147483647;
	min_max_idx = -1;
	idx = 0;
	while (node)
	{
		if (node->value >= ref && node->value <= min_max)
		{
			min_max = node->value;
			min_max_idx = idx;
		}
		idx++;
		node = node->prev;
	}
	return (min_max_idx);
}
