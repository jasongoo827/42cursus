/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:09 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/18 13:34:11 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_hard(t_push_swap *ps, int cnt)
{
	int	flag;

	flag = 0;
	if (cnt == 3)
		ps_cnt_3(ps->a);
	else if (cnt == 4)
	{
		ps_cnt_4(ps, 4);
		ps_cnt_3(ps->a);
		push_rotate(ps);
	}
	else if (cnt == 5)
	{
		ps_cnt_5(ps, &flag);
		if (flag == 0)
			ps_cnt_4(ps, 4);
		else
		{
			ps_cnt_4(ps, 5);
			swap(ps, ps->b);
		}
		ps_cnt_3(ps->a);
		push_rotate(ps);
		push_rotate(ps);
	}
}

void	ps_cnt_3(t_stack *stack)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = stack->edges[REAR]->prev->data;
	n2 = stack->edges[REAR]->prev->prev->data;
	n3 = stack->edges[REAR]->prev->prev->prev->data;
	if (n1 == 1 && n2 == 3 && n3 == 2)
		ft_printf("sa\nra\n");
	else if (n1 == 2 && n2 == 1 && n3 == 3)
		ft_printf("sa\n");
	else if (n1 == 3 && n2 == 1 && n3 == 2)
		ft_printf("ra\n");
	else if (n1 == 2 && n2 == 3 && n3 == 1)
		ft_printf("rra\n");
	else if (n1 == 3 && n2 == 2 && n3 == 1)
		ft_printf("sa\nrra\n");
}

void	ps_cnt_4(t_push_swap *ps, int data)
{
	int		i;
	t_node	*node;

	i = 1;
	node = ps->a->edges[REAR]->prev;
	while (node != ps->a->edges[FRONT])
	{
		if (node->data == data)
		{
			ps_cnt_4_util(ps, i);
			break ;
		}
		node = node->prev;
		i++;
	}
}

void	ps_cnt_5(t_push_swap *ps, int *flag)
{
	int		i;
	t_node	*node;

	i = 0;
	node = ps->a->edges[REAR]->prev;
	if (ps_cnt_front_5(ps, flag) == 1)
		return ;
	while (node != ps->a->edges[FRONT] && ++i < 5)
	{
		if (node->data == 4)
		{
			ps_cnt_5_util(ps, i);
			*flag = 1;
			break ;
		}
		if (node->data == 5)
		{
			ps_cnt_5_util(ps, i);
			break ;
		}
		node = node->prev;
	}
}

int	ps_cnt_front_5(t_push_swap *ps, int *flag)
{
	if (ps->a->edges[FRONT]->next->data == 4)
	{
		ps_cnt_5_util(ps, 5);
		*flag = 1;
		return (1);
	}
	else if (ps->a->edges[FRONT]->next->data == 5)
	{
		ps_cnt_5_util(ps, 5);
		return (1);
	}
	return (0);
}
