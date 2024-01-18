/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_adt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:52:16 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:52:17 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int *arr, int n)
{
	t_node	*node;
	int		i;

	i = -1;
	stack -> cnt = (unsigned int)n;
	while (++i < n)
	{
		node = create_node(arr[i]);
		node -> mod = arr[i];
		enque(stack, node, FRONT);
	}
}

void	init_stack_again(t_stack *stack, int *o_arr, int *m_arr)
{
	t_node	*node;
	int		i;

	node = stack->edges[REAR]->prev;
	i = 0;
	while (node != stack -> edges[FRONT])
	{
		node -> data = o_arr[i];
		node -> mod = m_arr[i];
		node -> rotate = 0;
		i++;
		node = node -> prev;
	}
}

// enque
void	enque(t_stack *stack, t_node *node, enum e_edge edge)
{
	if (edge == FRONT)
	{
		node -> next = stack -> edges[FRONT]-> next;
		node -> prev = stack -> edges[FRONT];
		stack -> edges[FRONT]-> next -> prev = node;
		stack -> edges[FRONT]-> next = node;
	}
	else
	{
		node -> next = stack -> edges[REAR];
		node -> prev = stack -> edges[REAR]-> prev;
		stack -> edges[REAR]-> prev -> next = node;
		stack -> edges[REAR]-> prev = node;
	}
}

// deque
t_node	*deque(t_stack	*stack, enum e_edge edge)
{
	t_node	*node;

	if (edge == FRONT)
	{
		node = stack -> edges[FRONT]-> next;
		stack -> edges[FRONT]-> next = node -> next;
		node -> next -> prev = stack -> edges[FRONT];
		node -> next = NULL;
		node -> prev = NULL;
	}
	else
	{
		node = stack -> edges[REAR]-> prev;
		stack -> edges[REAR]-> prev = node -> prev;
		node -> prev -> next = stack -> edges[REAR];
		node -> next = NULL;
		node -> prev = NULL;
	}
	return (node);
}
