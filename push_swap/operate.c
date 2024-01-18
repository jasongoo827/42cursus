/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:51:57 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:51:59 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap
void	swap(t_push_swap *ps, t_stack *stack)
{
	t_node	*node[2];

	if (stack -> cnt < 2)
		return ;
	node[0] = deque(stack, REAR);
	node[1] = deque(stack, REAR);
	enque(stack, node[0], REAR);
	enque(stack, node[1], REAR);
	ps -> cnt += 1;
	if (ps -> f_sort == 1)
		ft_printf("s%s\n", stack->name);
}

// push
void	push(t_push_swap *ps, t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (src -> cnt == 0)
		return ;
	node = deque(src, REAR);
	node -> mod /= 3;
	node -> rotate = 0;
	src -> cnt -= 1;
	enque(dst, node, REAR);
	dst -> cnt += 1;
	ps -> cnt += 1;
	ps -> tmp = NULL;
	if (ps -> f_sort == 1)
		ft_printf("p%s\n", dst->name);
}

// rotate
void	rotate(t_push_swap *ps, t_stack *stack, enum e_edge edge)
{
	t_node	*node;

	if (stack -> cnt < 2)
		return ;
	if (edge == FRONT)
	{
		node = deque(stack, FRONT);
		enque(stack, node, REAR);
	}
	else if (edge == REAR)
	{
		node = deque(stack, REAR);
		enque(stack, node, FRONT);
	}
	if (ps -> f_sort == 1)
	{
		if (edge == FRONT)
			ft_printf("rr%s\n", stack -> name);
		else
			ft_printf("r%s\n", stack -> name);
	}
	ps -> cnt += 1;
}

void	rotate_util(t_push_swap *ps, t_stack *stack)
{
	if (ps -> tmp == NULL)
	{
		ps -> tmp = stack;
		ps -> cnt += 1;
		if (ps -> f_sort == 1)
			ft_printf("r%s\n", stack -> name);
	}
	else
	{
		if (ps -> tmp != stack)
		{
			if (ps -> f_sort == 1)
				ft_printf("r%s\n", stack -> name);
			return ;
		}
		else
		{
			if (ps -> f_sort == 1)
				ft_printf("rr\n");
			ps -> cnt += 1;
		}
	}
}
