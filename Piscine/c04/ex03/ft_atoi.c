/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:08:39 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/02 13:26:06 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	s_idx;

	result = 0;
	s_idx = ft_count_negative(str, &sign);
	while (str[s_idx] && str[s_idx] >= '0' && str[s_idx] <= '9')
	{
		result *= 10;
		result += (str[s_idx] - '0');
		s_idx++;
	}
	return (result * sign);
}
