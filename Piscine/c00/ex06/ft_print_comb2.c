/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:37:37 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/29 16:53:05 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int a, int b)
{
	if (a < 10)
	{
		ft_putchar('0');
		ft_putchar(a + '0');
	}
	else
	{
		ft_putchar((a / 10) + '0');
		ft_putchar((a % 10) + '0');
	}
	ft_putchar(' ');
	if (b < 10)
	{
		ft_putchar('0');
		ft_putchar(b + '0');
	}
	else
	{
		ft_putchar((b / 10) + '0');
		ft_putchar((b % 10) + '0');
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 98)
	{
		while (b <= 99)
		{
			ft_print_number(a, b);
			if (a != 98)
				write(1, ", ", 2);
			b++;
		}
		a++;
		b = a + 1;
	}
}
