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

#include "push_swap_bonus.h"

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
}

// push
void	push(t_push_swap *ps, t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (src -> cnt == 0)
		return ;
	node = deque(src, REAR);
	src -> cnt -= 1;
	enque(dst, node, REAR);
	dst -> cnt += 1;
	ps -> cnt += 1;
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
	ps -> cnt += 1;
}
