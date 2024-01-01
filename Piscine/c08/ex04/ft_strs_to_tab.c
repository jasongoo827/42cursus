/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:28:08 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/31 12:07:55 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"ft_stock_str.h"

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

char	*ft_strdup(char *str)
{
	char	*d;
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	d = ret;
	if (!d)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int				i;
	t_stock_str		*arr;
	t_stock_str		*d;

	i = 0;
	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	d = arr;
	if (!d)
		return (0);
	while (i < ac)
	{
		arr[i].str = av[i];
		arr[i].size = ft_strlen(av[i]);
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
