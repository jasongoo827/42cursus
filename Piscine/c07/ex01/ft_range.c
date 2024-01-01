/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:43:55 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/01 10:29:48 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ret;
	int	*d;
	int	i;
	int	j;

	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	d = ret;
	if (!d)
		return (0);
	i = min;
	j = 0;
	while (j < (max - min))
		ret[j++] = i++;
	return (ret);
}
