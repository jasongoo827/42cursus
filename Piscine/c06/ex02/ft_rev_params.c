/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:31:22 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/27 20:31:58 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

int	main(int argc, char *argv[])
{
	int	j;

	j = argc - 1;
	while (j >= 1)
	{
		write(1, argv[j], ft_strlen(argv[j]));
		write(1, "\n", 1);
		j--;
	}
	return (0);
}
