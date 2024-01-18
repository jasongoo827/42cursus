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

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft/libft.h"
# include "../Libft/ft_printf/ft_printf.h"
# include "get_next_line.h"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	int				data;
	char			*cmd;
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
	t_stack			*a;
	t_stack			*b;
}	t_push_swap;

enum e_edge
{
	FRONT = 0,
	REAR
};

typedef enum e_cmd
{
	SA = 0,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	ERROR
}	t_cmd;

void		push_swap(int *arr, int cnt);
void		checker(t_push_swap *ps, int fd);
t_cmd		check_cmd_type(char *input, int len);
void		execute_cmd(t_push_swap *ps, t_cmd cmd);
void		execute_rrr(t_push_swap *ps, t_cmd cmd);
int			*normalize_arr(int *arr, int cnt);
int			check_dup(int *arr, int n);
int			check_sorted(int *arr, int cnt);
int			*parse_str(char *str, int *cnt);
int			*parse_num(char **strs, int n, int *cnt);
void		free_strs(char **strs);
int			check_str_digit(char *str);
int			check_str_int(char *str);
t_push_swap	*create_push_swap(int cnt);
t_stack		*create_stack(char *name, int cnt);
t_node		*create_node(int data, char *cmd);
void		free_push_swap(t_push_swap *ps);
void		free_stack(t_stack *stack);
void		init_stack(t_stack *stack, int *arr, int n);
void		enque(t_stack *stack, t_node *node, enum e_edge edge);
t_node		*deque(t_stack	*stack, enum e_edge edge);
void		swap(t_push_swap *ps, t_stack *stack);
void		push(t_push_swap *ps, t_stack *a, t_stack *b);
void		rotate(t_push_swap *ps, t_stack *stack, enum e_edge edge);
int			check_sorted(int *arr, int cnt);
int			check_stack_sorted(t_push_swap *ps);
void		iter_cmdlist(t_push_swap *ps, t_stack *stack);

#endif
