/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:29:45 by andorako          #+#    #+#             */
/*   Updated: 2024/05/07 14:33:37 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_set_flag(int *flag, int value)
{
	*flag = value;
	return (0);
}

int	ft_atoi_flag(char *str, int *flag)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (*str < '0' || *str > '9')
		return (ft_set_flag(flag, 0));
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		if (sign == -1 && res - 2147483648L > 0)
			return (ft_set_flag(flag, 0));
		else if (sign == 1 && res - 2147483647L > 0)
			return (ft_set_flag(flag, 0));
	}
	if (*str)
		return (ft_set_flag(flag, 0));
	return (res * sign);
}

int	ft_error(t_stack *st)
{
	write(2, "Error\n", 6);
	ft_clean_stack(st);
	return (1);
}

int	ft_check_duplicate_or_null(t_stack st)
{
	t_stack_node	*itr1;
	t_stack_node	*itr2;

	if (!st.head || !st.tail)
		return (1);
	itr1 = st.head;
	while (itr1)
	{
		itr2 = itr1->next;
		while (itr2)
		{
			if (itr2->value == itr1->value)
				return (1);
			itr2 = itr2->next;
		}
		itr1 = itr1->next;
	}
	return (0);
}
