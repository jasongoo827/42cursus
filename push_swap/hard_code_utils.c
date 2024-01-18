/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:34:21 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/18 13:34:23 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_cnt_4_util(t_push_swap *ps, int pos)
{
	if (pos == 1)
		push(ps, ps->a, ps->b);
	else if (pos == 2)
	{
		swap(ps, ps->a);
		push(ps, ps->a, ps->b);
	}
	else if (pos == 3)
	{
		rotate(ps, ps->a, FRONT);
		rotate(ps, ps->a, FRONT);
		push(ps, ps->a, ps->b);
	}
	else
	{
		rotate(ps, ps->a, FRONT);
		push(ps, ps->a, ps->b);
	}
}

void	ps_cnt_5_util(t_push_swap *ps, int pos)
{
	if (pos == 1)
		push(ps, ps->a, ps->b);
	else if (pos == 2)
	{
		swap(ps, ps->a);
		push(ps, ps->a, ps->b);
	}
	else if (pos == 3)
	{
		rotate(ps, ps->a, FRONT);
		rotate(ps, ps->a, FRONT);
		rotate(ps, ps->a, FRONT);
		push(ps, ps->a, ps->b);
	}
	else if (pos == 4)
	{
		rotate(ps, ps->a, FRONT);
		rotate(ps, ps->a, FRONT);
		push(ps, ps->a, ps->b);
	}
	else
	{
		rotate(ps, ps->a, FRONT);
		push(ps, ps->a, ps->b);
	}
}

void	push_rotate(t_push_swap *ps)
{
	push(ps, ps->b, ps->a);
	rotate(ps, ps->a, REAR);
}
