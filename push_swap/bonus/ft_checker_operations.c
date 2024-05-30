/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:48:17 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 10:52:09 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker_push_back(t_stack *st, int val)
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

long	ft_checker_pop_back(t_stack *st)
{
	int				tail_value;
	t_stack_node	*curr_tail;

	if (!st->head || !st->tail)
		return (INVALID_POP);
	curr_tail = st->tail;
	st->tail = st->tail->prev;
	tail_value = curr_tail->value;
	st->length--;
	free(curr_tail);
	return (tail_value);
}

void	ft_checker_swap_op(t_stack *st)
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

void	ft_checker_rotate_op(t_stack *st)
{
	t_stack_node	*tp_node;

	if (!st || !st->head || !st->tail || st->head == st->tail)
		return ;
	tp_node = st->tail;
	if (tp_node->prev == st->head)
	{
		ft_checker_swap_op(st);
		return ;
	}
	st->tail = st->tail->prev;
	st->tail->next = NULL;
	tp_node->prev = NULL;
	st->head->prev = tp_node;
	tp_node->next = st->head;
	st->head = tp_node;
}

void	ft_checker_reverse_rotate_op(t_stack *st)
{
	t_stack_node	*bt_node;

	if (!st || !st->head || !st->tail || st->head == st->tail)
		return ;
	bt_node = st->head;
	if (bt_node->next == st->tail)
	{
		ft_checker_swap_op(st);
		return ;
	}
	st->head = st->head->next;
	st->head->prev = NULL;
	bt_node->next = NULL;
	st->tail->next = bt_node;
	bt_node->prev = st->tail;
	st->tail = bt_node;
}
