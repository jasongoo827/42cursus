/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:30:50 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/01 10:33:56 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;
	int	*buffer;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	buffer = (int *)malloc(sizeof(int) * (max - min));
	*range = buffer;
	if (!(*range))
		return (-1);
	i = min;
	j = 0;
	while (j < (max - min))
	{
		buffer[j] = i;
		j++;
		i++;
	}
	return (max - min);
}
