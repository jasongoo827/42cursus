/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 18:56:41 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/29 13:55:32 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	ret = nb;
	while (nb > 1)
	{
		ret *= (nb - 1);
		nb--;
	}
	return (ret);
}
