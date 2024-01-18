/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:52:24 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:52:25 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*normalize_arr(int *arr, int cnt)
{
	int	*ret;
	int	i;
	int	j;

	ret = (int *)malloc(sizeof(int) * cnt);
	if (ret == NULL)
		exit(1);
	i = -1;
	while (++i < cnt)
		ret[i] = 0;
	i = -1;
	while (++i < cnt)
	{
		j = -1;
		while (++j < cnt)
		{
			if (arr[i] >= arr[j])
				ret[i]++;
		}
	}
	return (ret);
}

int	check_dup(int *arr, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			if (i == j)
				continue ;
			if (arr[i] == arr[j])
				return (0);
		}
	}
	return (1);
}

int	check_sorted(int *arr, int cnt)
{
	int	i;
	int	sort;

	i = 0;
	sort = arr[0];
	while (++i < cnt)
	{
		if (sort > arr[i])
			return (0);
		sort = arr[i];
	}
	return (1);
}

int	check_stack_sorted(t_push_swap *ps)
{
	t_node	*node;
	int		min;

	if (ps -> b -> cnt != 0)
		return (0);
	node = ps -> a -> edges[REAR]-> prev;
	min = node -> data;
	while (node != ps -> a -> edges[FRONT])
	{
		node = node -> prev;
		if (min > node -> data)
			return (0);
		min = node -> data;
	}
	return (1);
}

void	iter_cmdlist(t_push_swap *ps, t_stack *stack)
{
	t_node	*node;
	t_cmd	cmd;

	node = stack -> edges[REAR]-> prev;
	while (node != stack -> edges[FRONT])
	{
		cmd = check_cmd_type(node->cmd, ft_strlen(node->cmd) - 1);
		if (cmd != ERROR)
			execute_cmd(ps, cmd);
		else
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		node = node -> prev;
	}
}
