/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:02:30 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/01 11:08:39 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str);

int	ft_nbrlen(long nbr, int arith)
{
	int		len;
	long	nb;

	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	len = 0;
	while (nb != 0)
	{
		nb /= (long)arith;
		len++;
	}
	return (len);
}

void	ft_initialize(long nbr, int arith, char *str, char *base)
{
	int	i;

	i = ft_nbrlen(nbr, arith) - 1;
	if (str[0] == '-')
		i = ft_nbrlen(nbr, arith);
	if (nbr == 0)
	{
		str[0] = base[0];
		return ;
	}
	while (nbr != 0)
	{
		str[i--] = base[nbr % arith];
		nbr /= arith;
	}
}

char	*ft_convert_base2(long nbr, char *base_to)
{
	int		len;
	int		arith;
	char	*ret;
	char	*d;

	arith = ft_strlen(base_to);
	len = ft_nbrlen(nbr, arith);
	if (nbr < 0)
		len += 1;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	d = ret;
	if (!d)
		return (0);
	if (nbr < 0)
	{
		ret[0] = '-';
		nbr = -nbr;
	}
	ft_initialize(nbr, arith, ret, base_to);
	if (nbr != 0)
		ret[len] = '\0';
	else
		ret[1] = '\0';
	return (ret);
}
