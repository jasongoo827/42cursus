/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:35:04 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/01 16:42:48 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

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

int	ft_count_total_size(int size, char **strs, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < size)
	{
		count += ft_strlen(strs[i]);
		count += ft_strlen(sep);
		i++;
	}
	count -= ft_strlen(sep);
	return (count);
}

void	ft_join(char *buf, int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*s_addr;

	i = 0;
	j = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k] != '\0')
			buf[j++] = strs[i][k++];
		if (i < size - 1)
		{
			s_addr = sep;
			while (*s_addr != '\0')
			{
				buf[j++] = *s_addr;
				s_addr++;
			}
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*buf;
	char	*d;
	int		total_size;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	total_size = ft_count_total_size(size, strs, sep);
	buf = (char *)malloc(sizeof(char) * (total_size + 1));
	d = buf;
	if (!d)
		return (0);
	ft_join(buf, size, strs, sep);
	buf[total_size] = '\0';
	return (d);
}
