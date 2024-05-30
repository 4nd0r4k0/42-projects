/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:25:33 by andorako          #+#    #+#             */
/*   Updated: 2024/05/08 13:26:14 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_op(t_stack *st)
{
	t_stack_node	*top;
	t_stack_node	*prev_top;
	t_stack_node	*prev_prev_top;

	if (!st || !st->head || !st->tail || st->head == st->tail)
		return ;
	top = st->tail;
	prev_top = top->prev;
	prev_prev_top = prev_top->prev;
	top->next = prev_top;
	prev_top->prev = top;
	prev_top->next = NULL;
	if (prev_prev_top)
	{
		prev_prev_top->next = top;
		top->prev = prev_prev_top;
	}
	else
	{
		top->prev = NULL;
		st->head = top;
	}
	st->tail = prev_top;
}

void	ft_swap_and_print(t_stack *st, int stack_a)
{
	if (stack_a)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	ft_swap_op(st);
}

void	ft_rotate_op(t_stack *st, int print_op, int stack_a)
{
	t_stack_node	*tp_node;

	if (!st || !st->head || !st->tail || st->head == st->tail)
		return ;
	if (print_op)
	{
		if (stack_a)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	tp_node = st->tail;
	if (tp_node->prev == st->head)
	{
		ft_swap_op(st);
		return ;
	}
	st->tail = st->tail->prev;
	st->tail->next = NULL;
	tp_node->prev = NULL;
	st->head->prev = tp_node;
	tp_node->next = st->head;
	st->head = tp_node;
}

void	ft_reverse_rotate_op(t_stack *st, int print_op, int stack_a)
{
	t_stack_node	*bt_node;

	if (!st || !st->head || !st->tail || st->head == st->tail)
		return ;
	if (print_op)
	{
		if (stack_a)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	bt_node = st->head;
	if (bt_node->next == st->tail)
	{
		ft_swap_op(st);
		return ;
	}
	st->head = st->head->next;
	st->head->prev = NULL;
	bt_node->next = NULL;
	st->tail->next = bt_node;
	bt_node->prev = st->tail;
	st->tail = bt_node;
}
