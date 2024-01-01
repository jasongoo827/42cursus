/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:44:42 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/24 15:15:01 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*temp;
	unsigned int	i;

	temp = dest;
	i = 0;
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && (i++) < nb)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}
