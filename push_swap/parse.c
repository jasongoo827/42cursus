/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:52:07 by jgoo              #+#    #+#             */
/*   Updated: 2024/01/15 12:52:09 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_str(char *str, int *cnt)
{
	char	**strs;
	int		i;
	int		*ret;

	i = 0;
	strs = ft_split((const char *)str, ' ');
	while (strs[i] != NULL)
		i++;
	ret = (int *)malloc(sizeof(int) * i);
	if (ret == NULL)
		exit(1);
	i = 0;
	while (strs[i] != NULL)
	{
		if (check_str_digit(strs[i]) == 0 || check_str_int(strs[i]) == 0)
		{
			free(ret);
			return (NULL);
		}
		ret[i] = ft_atoi((const char *)strs[i]);
		i++;
	}
	*cnt = i;
	free_strs(strs);
	return (ret);
}

int	*parse_num(char **strs, int n, int *cnt)
{
	int	i;
	int	j;
	int	*ret;

	i = -1;
	j = 0;
	*cnt = n;
	ret = (int *)malloc(sizeof(int) * n);
	if (ret == NULL)
		exit(1);
	while (++i < n)
	{
		if (check_str_digit(strs[i]) == 0 || check_str_int(strs[i]) == 0)
		{
			free(ret);
			return (NULL);
		}
		ret[i] = ft_atoi(strs[i]);
	}
	return (ret);
}

void	free_strs(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		free(strs[i]);
	free(strs);
}

int	check_str_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[0] == '-')
	{
		if (str[1] == '\0')
			return (0);
		while (str[++i] != '\0')
		{
			if (ft_isdigit(str[i] - '0') == 0)
				return (0);
		}
		return (1);
	}
	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i] - '0') == 0)
			return (0);
	}
	return (1);
}

int	check_str_int(char *str)
{
	int			i;
	long long	ret;
	int			sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (ret * sign > (long long)MAX_INT || ret * sign < (long long)MIN_INT)
		return (0);
	return (1);
}
