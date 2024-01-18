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

#include "push_swap.h"

int	check_group(t_stack *stack)
{
	t_node	*front;
	t_node	*node;

	node = stack -> edges[REAR]-> prev;
	front = stack -> edges[FRONT];
	while (node != front)
	{
		if (node -> mod % 3 != 2)
			return (0);
		node = node -> prev;
	}
	return (1);
}

int	check_rotate(t_stack *stack)
{
	t_node	*front;
	t_node	*node;

	node = stack -> edges[REAR]-> prev;
	front = stack -> edges[FRONT];
	while (node != front)
	{
		if (node -> rotate == 1)
			return (0);
		node = node -> prev;
	}
	return (1);
}

int	*dup_arr(int *arr, int cnt)
{
	int	*ret;
	int	i;

	ret = (int *)malloc(sizeof(int) * cnt);
	if (ret == NULL)
		exit(1);
	i = -1;
	while (++i < cnt)
		ret[i] = arr[i];
	return (ret);
}

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

void	normalize_by_stack(t_stack *stack, int *arr, int cnt)
{
	t_node	*node;
	int		i;
	int		j;

	i = -1;
	while (++i < cnt)
	{
		node = stack -> edges[REAR];
		j = -1;
		while (++j < arr[i])
			node = node -> prev;
		arr[i] = node -> data;
	}
}
