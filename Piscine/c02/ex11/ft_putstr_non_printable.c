/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:36:40 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/29 12:00:39 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;

	while (*str != '\0')
	{
		c = *str;
		if (!(c >= 32 && c <= 126))
		{
			ft_putstr('\\');
			ft_putstr("0123456789abcdef"[c / 16]);
			ft_putstr("0123456789abcdef"[c % 16]);
		}
		else
			ft_putstr(c);
		str++;
	}
}
