/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andorako <andorako@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:29:18 by andorako          #+#    #+#             */
/*   Updated: 2024/05/10 09:22:34 by andorako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

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

void					ft_push_back(t_stack *st, int val);
int						ft_pop_back(t_stack *st, int print_op, int from_b);

int						ft_atoi_flag(char *str, int *flag);
int						ft_error(t_stack *st);
int						ft_check_duplicate_or_null(t_stack st);
char					**ft_split_sz(char *str, int *word_count);
char					**ft_clean_split(char **splitted);
void					ft_solve(t_stack *a);
void					ft_clean_stack(t_stack *st);

void					ft_swap_op(t_stack *st);
void					ft_swap_and_print(t_stack *st, int stack_a);
void					ft_rotate_op(t_stack *st, int print_op, int stack_a);
void					ft_reverse_rotate_op(t_stack *st, int print_op,
							int stack_a);

void					ft_sort_3(t_stack *st);
void					ft_sort_5(t_stack *st);
void					ft_sort_general(t_stack *st);
int						ft_is_sorted(t_stack *st);
void					ft_sort(t_stack *st);

int						ft_get_min_idx(t_stack *st);
int						ft_min_value(int a, int b);
int						ft_max_value(int a, int b);
void					ft_init_stack(t_stack *st);

int						ft_max_min_idx(t_stack *st, int ref);
int						ft_min_max_idx(t_stack *st, int ref);

void					ft_rotate_up(t_stack *a, t_stack *b, int idxa,
							int idxb);
void					ft_rotate_down(t_stack *a, t_stack *b, int idxa,
							int idxb);
void					ft_other_action(t_stack *a, t_stack *b, int idxa,
							int idxb);

void					ft_best_operation_b(t_stack *a, t_stack *b);
void					ft_best_operation_a(t_stack *a, t_stack *b, int idxa,
							int idxb);
void					ft_find_best_cost_a(t_stack *a, t_stack *b, int *idxa,
							int *idxb);

void					ft_rotate_min_value(t_stack *st);

#endif
