/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:38:36 by andorako          #+#    #+#             */
/*   Updated: 2024/03/28 09:38:39 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define N 1025

typedef struct s_list_node
{
	char				*str;
	int					end;
	struct s_list_node	*next;
}	t_list_node;

typedef struct s_list
{
	t_list_node	*head;
	t_list_node	*tail;
	int			end_count;
}	t_list;

void	ft_push_backb(t_list *l_begin, char *str, int end);

char	*get_next_line(int fd);

char	*ft_joinb(t_list *l_begin);

char	*ft_subb(char *str, int length);

void	ft_pushb(t_list *l_begin, char *str, int length, int is_end);

int		ft_strs_sizeb(t_list_node *node);

char	*ft_cleanb(t_list *l_begin, int del_all);

void	*ft_allocb(int sz);

int		ft_next_startb(t_list *l_begin, char *buff, int bytes);

#endif
