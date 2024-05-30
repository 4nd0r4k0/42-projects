/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:38:48 by andorako          #+#    #+#             */
/*   Updated: 2024/05/07 12:46:34 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve(t_stack *a)
{
	ft_sort(a);
	ft_clean_stack(a);
	return ;
}

static int	ft_calculate_cost(t_stack *a, t_stack *b, int a_cost, int b_cost)
{
	int	best_cost;

	best_cost = ft_max_value(a_cost, b_cost);
	if (ft_max_value(a->length - a_cost, b->length - b_cost) < best_cost)
		best_cost = ft_max_value(a->length - a_cost, b->length - b_cost);
	if (ft_min_value(b->length - b_cost + a_cost, a->length - a_cost
			+ b_cost) < best_cost)
		best_cost = ft_min_value(b->length - b_cost + a_cost, a->length - a_cost
				+ b_cost);
	return (best_cost);
}

void	ft_find_best_cost_a(t_stack *a, t_stack *b, int *idxa, int *idxb)
{
	int				best_cost;
	int				b_cost;
	int				a_cost;
	t_stack_node	*ita;

	a_cost = 0;
	ita = a->tail;
	best_cost = 2147483647;
	while (ita)
	{
		b_cost = ft_max_min_idx(b, ita->value);
		if (b_cost == -1)
			b_cost = ft_max_min_idx(b, 2147483647);
		if (ft_calculate_cost(a, b, a_cost, b_cost) < best_cost)
		{
			best_cost = ft_calculate_cost(a, b, a_cost, b_cost);
			*idxa = a_cost;
			*idxb = b_cost;
		}
		a_cost++;
		ita = ita->prev;
	}
}

void	ft_best_operation_a(t_stack *a, t_stack *b, int idxa, int idxb)
{
	if ((idxa * 2) <= a->length && (idxb * 2) <= b->length)
		ft_rotate_up(a, b, idxa, idxb);
	else if ((idxa * 2) > a->length && (idxb * 2) > b->length)
		ft_rotate_down(a, b, idxa, idxb);
	else
		ft_other_action(a, b, idxa, idxb);
	ft_push_back(b, ft_pop_back(a, 1, 0));
}

void	ft_best_operation_b(t_stack *a, t_stack *b)
{
	int	best_cost;
	int	a_cost;

	a_cost = ft_min_max_idx(a, b->tail->value);
	if (a_cost == -1)
		a_cost = ft_min_max_idx(a, -2147483648);
	best_cost = ft_min_value(a_cost, a->length - a_cost);
	while (best_cost-- > 0)
	{
		if ((a_cost * 2) <= a->length)
			ft_rotate_op(a, 1, 1);
		else
			ft_reverse_rotate_op(a, 1, 1);
	}
	ft_push_back(a, ft_pop_back(b, 1, 1));
}
