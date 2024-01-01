/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:12:07 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/02 12:12:13 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < length - 1 && sorted)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			sorted = 0;
		i++;
	}
	if (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i < length - 1 && sorted)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				sorted = 0;
			i++;
		}
	}
	return (sorted);
}
