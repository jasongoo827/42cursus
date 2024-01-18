/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:51:43 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:51:46 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*create_push_swap(int cnt)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (ps == NULL)
		exit(1);
	ps->cnt = 0;
	ps->f_sort = 0;
	ps->a = create_stack("a", cnt);
	ps->b = create_stack("b", 0);
	ps->tmp = NULL;
	return (ps);
}

t_stack	*create_stack(char *name, int cnt)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		exit(1);
	stack->cnt = cnt;
	stack->name = name;
	stack->edges[FRONT] = create_node(0);
	stack->edges[REAR] = create_node(0);
	stack->edges[FRONT]->next = stack->edges[REAR];
	stack->edges[FRONT]->prev = NULL;
	stack->edges[REAR]->prev = stack->edges[FRONT];
	stack->edges[REAR]->next = NULL;
	return (stack);
}

t_node	*create_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(1);
	node->mod = 0;
	node->data = data;
	node->rotate = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	free_push_swap(t_push_swap *ps)
{
	free_stack(ps->a);
	free_stack(ps->b);
	free(ps);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*delnode;

	node = stack->edges[FRONT];
	while (node != stack->edges[REAR])
	{
		delnode = node;
		free(delnode);
		node = node->next;
	}
	free(node);
	free(stack);
}
