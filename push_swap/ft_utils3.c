/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:10:19 by andorako          #+#    #+#             */
/*   Updated: 2024/05/08 13:28:26 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_value(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max_value(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_get_min_idx(t_stack *st)
{
	t_stack_node	*itr;
	int				min_value;
	int				min_idx;
	int				idx;

	idx = 0;
	itr = st->tail;
	min_value = 2147483647;
	while (itr)
	{
		if (itr->value < min_value)
		{
			min_value = itr->value;
			min_idx = idx;
		}
		itr = itr->prev;
		idx++;
	}
	return (min_idx);
}

void	ft_init_stack(t_stack *st)
{
	st->head = NULL;
	st->tail = NULL;
	st->length = 0;
}
