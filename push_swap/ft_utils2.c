/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:10:39 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 11:28:50 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_word(char *str)
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

static char	*ft_sb(char *str, int start, int end)
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

static char	**ft_fill_result(char **result, char *str)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 0;
	while (str[++j] != '\0')
	{
		if (str[j] == ' ')
		{
			if (j - i > 1)
				result[k++] = ft_sb(str, i + 1, j);
			i = j;
		}
	}
	if (j - i > 1)
		result[k] = ft_sb(str, i + 1, j);
	return (result);
}

char	**ft_split_sz(char *str, int *word_count)
{
	char	**result;

	if (!str || !*str)
		return (NULL);
	*word_count = ft_count_word(str);
	result = (char **)malloc(sizeof(char *) * (*word_count + 1));
	if (!result)
		return (NULL);
	result[*word_count] = (NULL);
	result = ft_fill_result(result, str);
	return (result);
}

char	**ft_clean_split(char **splitted)
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
