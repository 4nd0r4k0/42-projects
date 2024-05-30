/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:27:39 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 12:03:48 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_and_push(char **splitted, t_stack *st, int word_count)
{
	int	flag;
	int	num;

	if (!splitted)
		return (ft_error(st));
	while (--word_count >= 0)
	{
		flag = 1;
		num = ft_atoi_flag(splitted[word_count], &flag);
		if (!flag)
		{
			ft_clean_split(splitted);
			return (ft_error(st));
		}
		ft_push_back(st, num);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	char	**splitted;
	int		word_count;

	if (argc == 1)
		return (0);
	ft_init_stack(&a);
	while (argc > 1)
	{
		splitted = ft_split_sz(argv[--argc], &word_count);
		if (ft_check_and_push(splitted, &a, word_count))
			return (1);
		ft_clean_split(splitted);
	}
	if (ft_check_duplicate_or_null(a))
		return (ft_error(&a));
	ft_solve(&a);
	return (0);
}
