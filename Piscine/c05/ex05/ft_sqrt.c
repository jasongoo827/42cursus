/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 19:06:31 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/28 18:21:47 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_sqrt(int nb)
{
	long long	i;
	long long	num;

	i = 1;
	num = nb;
	if (num < 0)
		return (0);
	while (i * i <= num)
	{
		if ((num / i == i) && (num % i == 0))
			return (i);
		i++;
	}
	return (0);
}
