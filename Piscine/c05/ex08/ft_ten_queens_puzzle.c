/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:12:07 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/29 11:55:55 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	abs(int num)
{
	if (num > 0)
		return (num);
	else
		return (-num);
}

int	ft_check_if_promising(int *chess, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (chess[i] >= 0)
		{
			if (chess[i] == chess[row])
				return (0);
			if ((row - i) == abs(chess[row] - chess[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_print(int *chess)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = chess[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

int	dfs(int *chess, int row)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (row == 10)
	{
		ft_print(chess);
		write(1, "\n", 1);
		return (1);
	}
	while (i < 10)
	{
		chess[row] = i;
		if (ft_check_if_promising(chess, row))
			cnt += dfs(chess, row + 1);
		i++;
	}
	return (cnt);
}

int	ft_ten_queens_puzzle(void)
{
	int	chess[10];

	return (dfs(chess, 0));
}
