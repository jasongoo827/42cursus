/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:21:50 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/09 13:00:25 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print(char *arr, int n, int idx, int arynbr)
{
	if (idx == n)
	{
		write(1, arr, n);
		if (arr[0] != 10 - n + '0')
			write(1, ", ", 2);
		return ;
	}
	arr[idx] = arynbr;
	while (arr[idx] < 10 + '0')
	{
		ft_print(arr, n, idx + 1, arr[idx] + 1);
		arr[idx]++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	ft_print(arr, n, 0, '0');
}

int main(void)
{
	ft_print_combn(3);

	return (0);
}
