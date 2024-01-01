/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:24:19 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/27 10:27:24 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_checkerror(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ftn_printbr(int arith, long long nb, char *base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_printnbr(arith, -nb, base);
	}
	else if (nb >= arith)
	{
		ft_printnbr(arith, nb / arith, base);
		ft_putchar(base[nb % arith]);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	arith;

	if (!ft_checkerror(base))
		return ;
	arith = ft_strlen(base);
	ft_printnbr(arith, nbr, base);
}
