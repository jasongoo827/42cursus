/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:52:49 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:52:51 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft/libft.h"
# include "./Libft/ft_printf/ft_printf.h"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	int				mod;
	int				data;
	int				rotate;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	unsigned int	cnt;
	char			*name;
	t_node			*edges[2];
}	t_stack;

typedef struct s_push_swap
{
	unsigned int	cnt;
	int				f_sort;
	t_stack			*a;
	t_stack			*b;
	t_stack			*tmp;
}	t_push_swap;

enum e_edge
{
	FRONT = 0,
	REAR
};

void		push_swap(int *arr, int cnt);
void		optimize(t_push_swap *ps, int *cnt);
void		ps_repeat(t_push_swap *ps, t_stack *a, t_stack *b, int *cnt);
void		ps_repeat_opt(t_push_swap *ps, t_stack *a, t_stack *b, int cnt);
int			*normalize_arr(int *arr, int cnt);
void		normalize_by_stack(t_stack *stack, int *arr, int cnt);
void		ps_radix_sort(t_push_swap *ps, t_stack *src, t_stack *dst);
void		ps_radix_opt(t_push_swap *ps, t_stack *src, t_stack *dst);
void		radix_case(t_push_swap *ps, t_stack *src, t_stack *dst);
int			*parse_str(char *str, int *cnt);
int			*parse_num(char **strs, int n, int *cnt);
void		free_strs(char **strs);
int			check_str_digit(char *str);
int			check_str_int(char *str);
t_push_swap	*create_push_swap(int cnt);
t_stack		*create_stack(char *name, int cnt);
t_node		*create_node(int data);
void		free_push_swap(t_push_swap *ps);
void		free_stack(t_stack *stack);
void		init_stack(t_stack *stack, int *arr, int n);
void		init_stack_again(t_stack *stack, int *o_arr, int *m_arr);
void		enque(t_stack *stack, t_node *node, enum e_edge edge);
t_node		*deque(t_stack	*stack, enum e_edge edge);
void		swap(t_push_swap *ps, t_stack *stack);
void		push(t_push_swap *ps, t_stack *a, t_stack *b);
void		rotate(t_push_swap *ps, t_stack *stack, enum e_edge edge);
void		rotate_util(t_push_swap *ps, t_stack *stack);
int			check_group(t_stack *stack);
int			check_rotate(t_stack *stack);
int			*dup_arr(int *arr, int cnt);
int			count_rep(t_push_swap *ps, int *cnt);
int			check_dup(int *arr, int n);
int			check_sorted(int *arr, int cnt);
void		push_swap_hard(t_push_swap *ps, int cnt);
void		ps_cnt_3(t_stack *stack);
void		ps_cnt_4(t_push_swap *ps, int data);
void		ps_cnt_5(t_push_swap *ps, int *flag);
int			ps_cnt_front_5(t_push_swap *ps, int *flag);
void		push_rotate(t_push_swap *ps);
void		ps_cnt_4_util(t_push_swap *ps, int pos);
void		ps_cnt_5_util(t_push_swap *ps, int pos);

#endif
