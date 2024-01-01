/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:47:39 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/01 11:10:09 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_convert_base2(long nbr, char *base_to);

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
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '
			|| str[i] == '+' || str[i] == '-')
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

int	ft_count_negative(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				*sign *= (-1);
			i++;
		}
		else
			break ;
	}
	return (i);
}

int	ft_is_in_base(char c, char *base)
{
	int	idx;

	idx = 0;
	while (*base != '\0')
	{
		if (*base == c)
			return (idx);
		base++;
		idx++;
	}
	return (-1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	result;
	int	sign;
	int	arith;
	int	s_idx;
	int	idx;

	result = 0;
	if (!ft_checkerror(base_from) || !ft_checkerror(base_to))
		return (0);
	s_idx = ft_count_negative(nbr, &sign);
	arith = ft_strlen(base_from);
	while (nbr[s_idx] && ft_is_in_base(nbr[s_idx], base_from) >= 0)
	{
		idx = ft_is_in_base(nbr[s_idx], base_from);
		result *= arith;
		result += idx;
		s_idx++;
	}
	result *= sign;
	return (ft_convert_base2(result, base_to));
}
