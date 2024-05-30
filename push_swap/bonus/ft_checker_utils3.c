/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 10:39:10 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 11:12:54 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_checker_init_stack(t_stack *a, t_stack *b)
{
	if (a)
	{
		a->head = (NULL);
		a->tail = (NULL);
		a->length = (0);
	}
	if (b)
	{
		b->head = (NULL);
		b->tail = (NULL);
		b->length = (0);
	}
}

void	ft_checker_clean_stack(t_stack *a)
{
	t_stack_node	*next_node;
	t_stack_node	*node;

	if (!a)
		return ;
	node = a->head;
	while (node)
	{
		next_node = node->next;
		free(node);
		node = next_node;
	}
	ft_checker_init_stack(a, NULL);
}

int	ft_checker_check_and_apply_cmd(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (ft_apply_cmd(a, b, cmd) == FAILURE_CMD)
		{
			free(cmd);
			return (ft_checker_error(a, b));
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	return (0);
}

int	ft_checker_contains_duplicate(t_stack *a)
{
	t_stack_node	*node1;
	t_stack_node	*node2;

	node1 = a->head;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			if (node2->value == node1->value)
				return (1);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (0);
}
