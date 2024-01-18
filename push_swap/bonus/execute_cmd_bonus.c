/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:31:52 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/18 13:31:54 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_cmd	check_cmd_type(char *input, int len)
{
	if (len <= 1)
		return (ERROR);
	if (ft_strncmp(input, "sa", len) == 0)
		return (SA);
	else if (ft_strncmp(input, "sb", len) == 0)
		return (SB);
	else if (ft_strncmp(input, "ss", len) == 0)
		return (SS);
	else if (ft_strncmp(input, "pa", len) == 0)
		return (PA);
	else if (ft_strncmp(input, "pb", len) == 0)
		return (PB);
	else if (ft_strncmp(input, "ra", len) == 0)
		return (RA);
	else if (ft_strncmp(input, "rb", len) == 0)
		return (RB);
	else if (ft_strncmp(input, "rr", len) == 0)
		return (RR);
	else if (ft_strncmp(input, "rra", len) == 0)
		return (RRA);
	else if (ft_strncmp(input, "rrb", len) == 0)
		return (RRB);
	else if (ft_strncmp(input, "rrr", len) == 0)
		return (RRR);
	return (ERROR);
}

void	execute_cmd(t_push_swap *ps, t_cmd cmd)
{
	if (cmd == SA)
		swap(ps, ps -> a);
	else if (cmd == SB)
		swap(ps, ps -> b);
	else if (cmd == SS)
	{
		swap(ps, ps -> a);
		swap(ps, ps -> b);
	}
	else if (cmd == PA)
		push(ps, ps -> b, ps -> a);
	else if (cmd == PB)
		push(ps, ps -> a, ps -> b);
	else if (cmd == RA)
		rotate(ps, ps -> a, REAR);
	else if (cmd == RB)
		rotate(ps, ps -> b, REAR);
	else if (cmd == RR)
	{
		rotate(ps, ps -> a, REAR);
		rotate(ps, ps -> b, REAR);
	}
	else if (cmd == RRA || cmd == RRB || cmd == RRR)
		execute_rrr(ps, cmd);
}

void	execute_rrr(t_push_swap *ps, t_cmd cmd)
{
	if (cmd == RRA)
		rotate(ps, ps -> a, FRONT);
	else if (cmd == RRB)
		rotate(ps, ps -> b, FRONT);
	else if (cmd == RRR)
	{
		rotate(ps, ps -> a, FRONT);
		rotate(ps, ps -> b, FRONT);
	}
}
