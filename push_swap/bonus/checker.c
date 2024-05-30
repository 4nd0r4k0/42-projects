/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:25:56 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 11:32:51 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_checker_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	ft_checker_clean_stack(a);
	ft_checker_clean_stack(b);
	return (1);
}

static int	ft_checker_check_and_push(char **splitted, t_stack *st,
		int word_count)
{
	int	flag;
	int	num;

	if (!splitted || !*splitted)
		return (ft_checker_error(st, NULL));
	while (--word_count >= 0)
	{
		flag = 1;
		num = ft_checker_atoi_flag(splitted[word_count], &flag);
		if (!flag)
		{
			ft_checker_clean_split(splitted);
			return (ft_checker_error(st, NULL));
		}
		ft_checker_push_back(st, num);
	}
	return (0);
}

static int	ft_checker_is_sorted(t_stack *st)
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

static int	ft_checker_find_result(t_stack *a, t_stack *b)
{
	if (ft_checker_is_sorted(a) && b->length == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_checker_clean_stack(a);
	ft_checker_clean_stack(b);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**splitted;
	int		word_count;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (1);
	ft_checker_init_stack(&a, &b);
	while (argc > 1)
	{
		splitted = ft_checker_split_sz(argv[--argc], &word_count);
		if (ft_checker_check_and_push(splitted, &a, word_count))
			return (1);
		ft_checker_clean_split(splitted);
	}
	if (ft_checker_contains_duplicate(&a))
		return (ft_checker_error(&a, &b));
	if (ft_checker_check_and_apply_cmd(&a, &b))
		return (1);
	return (ft_checker_find_result(&a, &b));
}
