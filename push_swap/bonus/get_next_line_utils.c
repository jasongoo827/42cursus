/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:01:06 by jgoo              #+#    #+#             */
/*   Updated: 2023/11/04 17:01:08 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	remove_lst(t_list_gnl **lst, t_list_gnl *node, int fd)
{
	t_list_gnl	*past;

	past = NULL;
	while (node != NULL)
	{
		if (node -> fd == fd)
		{
			if (node -> buf != NULL)
				free(node -> buf);
			node -> buf = NULL;
			if (past == NULL)
				*lst = node -> next;
			else
				past -> next = node -> next;
			node -> next = NULL;
			free(node);
			node = NULL;
			break ;
		}
		past = node;
		node = node -> next;
	}
}

char	*ft_substr_gnl(char *buf)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\0' || ft_strlen(buf) - (i + 1) == 0)
	{
		free(buf);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i));
	if (line == NULL)
	{
		free(buf);
		return (NULL);
	}
	i++;
	j = 0;
	while (buf[i])
		line[j++] = buf[i++];
	line[j] = '\0';
	free(buf);
	return (line);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	free(s1);
	return (ret);
}

int	ft_strchr_gnl(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
