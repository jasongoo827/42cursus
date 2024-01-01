/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:32:41 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/28 17:08:44 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_print(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		x;
	int		y;
	char	*temp;

	x = 1;
	while (x < argc)
	{
		y = 1;
		while (y < argc - x)
		{
			if (ft_strcmp(argv[y], argv[y + 1]) > 0)
			{
				temp = argv[y];
				argv[y] = argv[y + 1];
				argv[y + 1] = temp;
			}
			y++;
		}
		x++;
	}
	ft_print(argc, argv);
	return (0);
}
