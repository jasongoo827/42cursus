/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:47:58 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/05 09:23:07 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
int		ft_atoi(char *str);

void	ft_calculate(int x, int y, char op)
{
	if (op == '+')
		ft_putnbr(x + y);
	else if (op == '-')
		ft_putnbr(x - y);
	else if (op == '/')
	{
		if (y == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(x / y);
	}
	else if (op == '*')
		ft_putnbr(x * y);
	else if (op == '%')
	{
		if (y == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(x % y);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
