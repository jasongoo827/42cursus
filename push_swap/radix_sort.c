/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:02 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 15:50:03 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_radix_sort(t_push_swap *ps, t_stack *src, t_stack *dst)
{
	t_node	*node;

	while (src -> cnt != 0)
	{
		node = src -> edges[REAR]-> prev;
		if ((node -> mod) % 3 == 0)
			push(ps, src, dst);
		else if ((node -> mod) % 3 == 1)
		{
			push(ps, src, dst);
			rotate(ps, dst, REAR);
		}
		else if ((node -> mod) % 3 == 2)
		{
			if (check_group(src) == 1)
			{
				if (check_rotate(src) == 1 || node -> rotate)
					break ;
			}
			rotate(ps, src, REAR);
			node -> rotate = 1;
		}
	}
	while (src -> cnt != 0)
		push(ps, src, dst);
}

void	ps_radix_opt(t_push_swap *ps, t_stack *src, t_stack *dst)
{
	t_node	*node;

	while (src -> cnt != 0)
	{
		node = src -> edges[REAR]-> prev;
		if ((node -> mod) % 4 == 0 || (node -> mod) % 4 == 1 \
		|| (node -> mod) % 4 == 2)
			radix_case(ps, src, dst);
		else
		{
			if (node -> rotate == 1)
			{
				push(ps, src, dst);
				rotate(ps, dst, REAR);
			}
			else
			{
				rotate(ps, src, REAR);
				node -> rotate = 1;
			}
		}
	}
}

void	radix_case(t_push_swap *ps, t_stack *src, t_stack *dst)
{
	t_node	*node;

	node = src -> edges[REAR]-> prev;
	if ((node -> mod) % 4 == 0)
		push(ps, src, dst);
	else if ((node -> mod) % 4 == 1)
	{
		push(ps, src, dst);
		rotate(ps, dst, REAR);
	}
	else if ((node -> mod) % 4 == 2)
	{
		if (node -> rotate == 1)
			push(ps, src, dst);
		else
		{
			rotate(ps, src, REAR);
			node -> rotate = 1;
		}
	}
}
