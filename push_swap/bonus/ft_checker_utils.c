/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:39:11 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 11:15:41 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_is_equal(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i])
	{
		if (a[i] != b[i])
			return (0);
		else
			i++;
	}
	return (a[i] == '\0' && b[i] == '\0');
}

int	ft_apply_cmd(t_stack *a, t_stack *b, char *cmd)
{
	if (ft_is_equal(cmd, "sa\n") || ft_is_equal(cmd, "sb\n") || ft_is_equal(cmd,
			"ss\n"))
		return (ft_check_swap(a, b, cmd));
	else if (ft_is_equal(cmd, "pa\n") || ft_is_equal(cmd, "pb\n"))
		return (ft_check_push(a, b, cmd));
	else if (ft_is_equal(cmd, "ra\n") || ft_is_equal(cmd, "rb\n")
		|| ft_is_equal(cmd, "rr\n"))
		return (ft_check_rotate(a, b, cmd));
	else if (ft_is_equal(cmd, "rra\n") || ft_is_equal(cmd, "rrb\n")
		|| ft_is_equal(cmd, "rrr\n"))
		return (ft_check_reverse_rotate(a, b, cmd));
	else
		return (FAILURE_CMD);
}

int	ft_checker_set_flag(int *flag)
{
	*flag = 0;
	return (0);
}

int	ft_checker_atoi_flag(char *str, int *flag)
{
	long	res;
	long	sign;

	res = 0;
	sign = 1;
	if (!str || !*str)
		return (ft_checker_set_flag(flag));
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (*str < '0' || *str > '9')
		return (ft_checker_set_flag(flag));
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		if (sign == -1 && res - 2147483648L > 0)
			return (ft_checker_set_flag(flag));
		else if (sign == 1 && res - 2147483647L > 0)
			return (ft_checker_set_flag(flag));
	}
	if (*str)
		return (ft_checker_set_flag(flag));
	return (res * sign);
}
