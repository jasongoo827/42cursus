/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:13:45 by jgoo              #+#    #+#             */
/*   Updated: 2023/07/24 16:24:42 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;
	int	diff;

	i = 0;
	diff = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += diff;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		isfirst;
	char	*temp;

	i = 0;
	isfirst = 1;
	temp = str;
	ft_strlowcase(str);
	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
		{
			if (isfirst)
				*str -= ('a' - 'A');
			isfirst = 0;
		}
		else if (*str >= '0' && *str <= '9')
			isfirst = 0;
		else
			isfirst = 1;
		str++;
	}
	return (temp);
}	
