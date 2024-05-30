/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:37:19 by andorako          #+#    #+#             */
/*   Updated: 2024/03/28 09:38:07 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define TRUE 1

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

void	ft_push_back(t_list *l_begin, char *str, int end);

char	*get_next_line(int fd);

char	*ft_join(t_list *l_begin);

char	*ft_sub(char *str, int length);

void	ft_push(t_list *l_begin, char *str, int length, int is_end);

int		ft_strs_size(t_list_node *l_begin);

char	*ft_clean(t_list *l_begin, int del_all);

void	*ft_alloc(int sz);

int		ft_next_start(t_list *l_begin, char *buff, int bytes);

#endif
