/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:17:05 by andorako          #+#    #+#             */
/*   Updated: 2024/05/08 13:44:18 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_up(t_stack *a, t_stack *b, int idxa, int idxb)
{
	int	cost;

	cost = ft_min_value(idxa, idxb);
	while (cost-- > 0)
	{
		write(1, "rr\n", 3);
		ft_rotate_op(a, 0, 0);
		ft_rotate_op(b, 0, 0);
	}
	cost = ft_max_value(idxa, idxb) - ft_min_value(idxa, idxb);
	while (cost-- > 0)
	{
		if (idxa < idxb)
			ft_rotate_op(b, 1, 0);
		else
			ft_rotate_op(a, 1, 1);
	}
}

void	ft_rotate_down(t_stack *a, t_stack *b, int idxa, int idxb)
{
	int	cost;

	idxa = a->length - idxa;
	idxb = b->length - idxb;
	cost = ft_min_value(idxa, idxb);
	while (cost-- > 0)
	{
		write(1, "rrr\n", 4);
		ft_reverse_rotate_op(a, 0, 0);
		ft_reverse_rotate_op(b, 0, 0);
	}
	cost = ft_max_value(idxa, idxb) - ft_min_value(idxa, idxb);
	while (cost-- > 0)
	{
		if (idxa < idxb)
			ft_reverse_rotate_op(b, 1, 0);
		else
			ft_reverse_rotate_op(a, 1, 1);
	}
}

void	ft_other_action(t_stack *a, t_stack *b, int idxa, int idxb)
{
	int		cost;

	cost = ft_min_value(idxa, a->length - idxa);
	while (cost-- > 0)
	{
		if ((idxa * 2) <= a->length)
			ft_rotate_op(a, 1, 1);
		else
			ft_reverse_rotate_op(a, 1, 1);
	}
	cost = ft_min_value(idxb, b->length - idxb);
	while (cost-- > 0)
	{
		if ((idxb * 2) <= b->length)
			ft_rotate_op(b, 1, 0);
		else
			ft_reverse_rotate_op(b, 1, 0);
	}
}
