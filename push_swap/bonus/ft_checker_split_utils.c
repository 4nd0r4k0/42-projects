/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_split_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:23:10 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 11:24:58 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_checker_count_word(char *str)
{
	int	i;
	int	j;
	int	w;

	i = -1;
	j = -1;
	w = 0;
	while (str[++j] != '\0')
	{
		if (str[j] == ' ')
		{
			w += (j - i > 1);
			i = j;
		}
	}
	w += (j - i > 1);
	return (w);
}

static char	*ft_checker_sb(char *str, int start, int end)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start + i < end)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**ft_checker_fill_result(char **result, char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = -1;
	k = 0;
	while (str[++j] != '\0')
	{
		if (str[j] == ' ')
		{
			if (j - i > 1)
				result[k++] = ft_checker_sb(str, i + 1, j);
			i = j;
		}
	}
	if (j - i > 1)
		result[k] = ft_checker_sb(str, i + 1, j);
	return (result);
}

char	**ft_checker_split_sz(char *str, int *word_count)
{
	char	**result;

	if (!str || !*str)
		return (NULL);
	*word_count = ft_checker_count_word(str);
	result = (char **)malloc(sizeof(char *) * (*word_count + 1));
	if (!result)
		return (NULL);
	result[*word_count] = (NULL);
	result = ft_checker_fill_result(result, str);
	return (result);
}

char	**ft_checker_clean_split(char **splitted)
{
	int	i;

	i = 0;
	if (!splitted)
		return (NULL);
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
	return (NULL);
}
