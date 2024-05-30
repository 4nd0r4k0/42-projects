/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:59:16 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 13:33:48 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *st)
{
	int				prev_value;
	t_stack_node	*itr;

	prev_value = -2147483648;
	itr = st->tail;
	while (itr)
	{
		if (itr->value < prev_value)
			return (0);
		prev_value = itr->value;
		itr = itr->prev;
	}
	return (1);
}

void	ft_sort_3(t_stack *st)
{
	if (st->length == 2)
	{
		if (st->tail->value > st->head->value)
			ft_swap_and_print(st, 1);
		return ;
	}
	if (st->tail->value > st->head->value)
	{
		if (st->tail->value > st->tail->prev->value)
		{
			ft_rotate_op(st, 1, 1);
			if (st->tail->value > st->tail->prev->value)
				ft_swap_and_print(st, 1);
		}
		else
			ft_reverse_rotate_op(st, 1, 1);
	}
	else if (!ft_get_min_idx(st))
	{
		ft_swap_and_print(st, 1);
		ft_rotate_op(st, 1, 1);
	}
	else if (st->tail->value < st->head->value)
		ft_swap_and_print(st, 1);
}

void	ft_sort_5(t_stack *st)
{
	t_stack	b;
	int		cost;
	int		turn;

	turn = 1 + (st->length == 5);
	ft_init_stack(&b);
	while (turn-- > 0)
	{
		cost = ft_get_min_idx(st);
		if ((cost * 2) <= st->length)
			while (cost-- > 0)
				ft_rotate_op(st, 1, 1);
		else
		{
			cost = st->length - cost;
			while (cost-- > 0)
				ft_reverse_rotate_op(st, 1, 1);
		}
		ft_push_back(&b, ft_pop_back(st, 1, 0));
	}
	if (!ft_is_sorted(st))
		ft_sort_3(st);
	ft_push_back(st, ft_pop_back(&b, 1, 1));
	if ((st->length + b.length) == 5)
		ft_push_back(st, ft_pop_back(&b, 1, 1));
}

void	ft_sort_general(t_stack *st)
{
	t_stack	b;
	int		idxa;
	int		idxb;

	ft_init_stack(&b);
	ft_push_back(&b, ft_pop_back(st, 1, 0));
	if (st->length > 5)
		ft_push_back(&b, ft_pop_back(st, 1, 0));
	while (st->length > 5 && !ft_is_sorted(st))
	{
		ft_find_best_cost_a(st, &b, &idxa, &idxb);
		ft_best_operation_a(st, &b, idxa, idxb);
	}
	if (!ft_is_sorted(st) && st->length == 5)
		ft_sort_5(st);
	while (b.length > 0)
		ft_best_operation_b(st, &b);
	if (!ft_is_sorted(st))
		ft_rotate_min_value(st);
}

void	ft_sort(t_stack *st)
{
	if (!st->head || !st->tail || st->head == st->tail || ft_is_sorted(st))
		return ;
	if (st->length <= 3)
		ft_sort_3(st);
	else if (st->length <= 5)
		ft_sort_5(st);
	else
		ft_sort_general(st);
}
