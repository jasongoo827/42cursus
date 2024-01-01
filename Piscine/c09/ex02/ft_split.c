/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:09:19 by jgoo              #+#    #+#             */
/*   Updated: 2023/08/01 11:17:49 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	check_seperator(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_cnt_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_seperator(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_seperator(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_word_dup(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;
	char	*d;

	i = 0;
	len = 0;
	while (str[i] != '\0' && !check_seperator(str[i], charset))
	{
		len++;
		i++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	d = word;
	if (!d)
		return (0);
	i = 0;
	while (str[i] != '\0' && !check_seperator(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**strs;
	char	**d;
	int		i;

	size = ft_cnt_word(str, charset);
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	d = strs;
	if (!d)
		return (0);
	i = 0;
	while (i < size)
	{
		while (*str != '\0' && check_seperator(*str, charset))
			str++;
		if (*str != '\0')
			strs[i] = ft_word_dup(str, charset);
		while (*str != '\0' && !check_seperator(*str, charset))
			str++;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
