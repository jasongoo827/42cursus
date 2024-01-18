/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:52:30 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:52:32 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	count_rep(t_push_swap *ps, int *cnt)
{
	int	rep;

	rep = 0;
	while (*cnt != 0)
	{
		*cnt /= 3;
		rep++;
	}
	*cnt = ps -> a -> cnt;
	return (rep);
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
