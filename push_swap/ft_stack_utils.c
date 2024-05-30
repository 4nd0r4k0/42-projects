/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:43:33 by andorako          #+#    #+#             */
/*   Updated: 2024/05/08 13:45:00 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_back(t_stack *st, int val)
{
	t_stack_node	*new_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = (val);
	new_node->next = (NULL);
	new_node->prev = (NULL);
	if (!st->head || !st->tail)
	{
		st->head = new_node;
		st->tail = new_node;
		st->length = 1;
		return ;
	}
	new_node->prev = st->tail;
	st->tail->next = (new_node);
	st->tail = (new_node);
	st->length++;
}

int	ft_pop_back(t_stack *st, int print_op, int from_b)
{
	int				tail_value;
	t_stack_node	*curr_tail;

	curr_tail = st->tail;
	st->tail = st->tail->prev;
	tail_value = curr_tail->value;
	st->length--;
	if (print_op)
	{
		if (from_b)
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
	free(curr_tail);
	return (tail_value);
}

void	ft_clean_stack(t_stack *st)
{
	t_stack_node	*itr;
	t_stack_node	*nxt;

	if (!st)
		return ;
	itr = st->head;
	while (itr)
	{
		nxt = itr->next;
		free(itr);
		itr = nxt;
	}
	ft_init_stack(st);
}

void	ft_rotate_min_value(t_stack *st)
{
	int	idx;
	int	cost;

	idx = ft_get_min_idx(st);
	cost = ft_min_value(idx, st->length - idx);
	while (cost-- > 0)
	{
		if ((idx * 2) <= st->length)
			ft_rotate_op(st, 1, 1);
		else
			ft_reverse_rotate_op(st, 1, 1);
	}
}
