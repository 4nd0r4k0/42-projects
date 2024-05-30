/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:27:09 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 11:53:54 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define INVALID_POP 2147483648L
# define SUCCESS_CMD 1
# define FAILURE_CMD 0
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

typedef struct s_stack
{
	t_stack_node		*head;
	t_stack_node		*tail;
	int					length;
}						t_stack;

char					*ft_gnl(int fd);
int						ft_is_equal(char *a, char *b);

void					ft_checker_swap_op(t_stack *st);
void					ft_checker_rotate_op(t_stack *st);
void					ft_checker_reverse_rotate_op(t_stack *st);
void					ft_checker_push_back(t_stack *st, int val);
long					ft_checker_pop_back(t_stack *st);

int						ft_check_swap(t_stack *a, t_stack *b, char *cmd);
int						ft_check_push(t_stack *a, t_stack *b, char *cmd);
int						ft_check_rotate(t_stack *a, t_stack *b, char *cmd);
int						ft_check_reverse_rotate(t_stack *a, t_stack *b,
							char *cmd);

int						ft_apply_cmd(t_stack *a, t_stack *b, char *cmd);
void					ft_checker_init_stack(t_stack *a, t_stack *b);

char					**ft_checker_split_sz(char *str, int *word_count);
char					**ft_checker_clean_split(char **splitted);
void					ft_checker_clean_stack(t_stack *a);
int						ft_checker_atoi_flag(char *str, int *flag);

int						ft_checker_contains_duplicate(t_stack *a);
int						ft_checker_check_and_apply_cmd(t_stack *a, t_stack *b);
int						ft_checker_error(t_stack *a, t_stack *b);

#endif