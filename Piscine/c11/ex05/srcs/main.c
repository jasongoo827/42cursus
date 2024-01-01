/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:24:42 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/03 15:49:22 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_calculate(int x, int y, char op);
int		ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	if (argc == 4)
		ft_calculate(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0]);
	return (0);
}
