/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:17:23 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/02 13:27:18 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	sign;
	int	arith;
	int	idx;
	int	s_idx;

	result = 0;
	if (!ft_checkerror(base))
		return (0);
	s_idx = ft_count_negative(str, &sign);
	arith = ft_strlen(base);
	while (str[s_idx] && ft_is_in_base(str[s_idx], base) >= 0)
	{
		idx = ft_is_in_base(str[s_idx], base);
		result *= arith;
		result += idx;
		s_idx++;
	}
	result *= sign;
	return (result);
}
