/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_cmd_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:04:36 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 11:58:21 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_swap(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_is_equal(cmd, "sa\n"))
	{
		if (a->length > 0)
			ft_checker_swap_op(a);
	}
	else if (ft_is_equal(cmd, "sb\n"))
	{
		if (b->length > 0)
			ft_checker_swap_op(b);
	}
	else if (ft_is_equal(cmd, "ss\n"))
	{
		if (a->length > 0 && b->length > 0)
		{
			ft_checker_swap_op(a);
			ft_checker_swap_op(b);
		}
	}
	return (SUCCESS_CMD);
}

int	ft_check_push(t_stack *a, t_stack *b, char *cmd)
{
	long	pop_value;

	if (ft_is_equal(cmd, "pa\n"))
	{
		pop_value = ft_checker_pop_back(b);
		if (pop_value != INVALID_POP)
			ft_checker_push_back(a, (int)pop_value);
	}
	else if (ft_is_equal(cmd, "pb\n"))
	{
		pop_value = ft_checker_pop_back(a);
		if (pop_value != INVALID_POP)
			ft_checker_push_back(b, (int)pop_value);
	}
	return (SUCCESS_CMD);
}

int	ft_check_rotate(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_is_equal(cmd, "ra\n"))
	{
		if (a->length > 0)
			ft_checker_rotate_op(a);
	}
	else if (ft_is_equal(cmd, "rb\n"))
	{
		if (b->length > 0)
			ft_checker_rotate_op(b);
	}
	else if (ft_is_equal(cmd, "rr\n"))
	{
		if (a->length > 0 && b->length > 0)
		{
			ft_checker_rotate_op(a);
			ft_checker_rotate_op(b);
		}
	}
	return (SUCCESS_CMD);
}

int	ft_check_reverse_rotate(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_is_equal(cmd, "rra\n"))
	{
		if (a->length > 0)
			ft_checker_reverse_rotate_op(a);
	}
	else if (ft_is_equal(cmd, "rrb\n"))
	{
		if (b->length > 0)
			ft_checker_reverse_rotate_op(b);
	}
	else if (ft_is_equal(cmd, "rrr\n"))
	{
		if (a->length > 0 && b->length > 0)
		{
			ft_checker_reverse_rotate_op(a);
			ft_checker_reverse_rotate_op(b);
		}
	}
	return (SUCCESS_CMD);
}
