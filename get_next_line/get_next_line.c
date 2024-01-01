/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:24:44 by jgoo              #+#    #+#             */
/*   Updated: 2023/10/21 14:16:34 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_free(char **buf)
{
	if (*buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
}

char	*ft_alloc_line(char **db, char *buf, unsigned int pos)
{
	char	*line;
	int		flag;

	if (buf != NULL)
		ft_free(&buf);
	line = ft_strdup(*db, pos + 1);
	if (line == NULL)
	{
		ft_free(db);
		return (NULL);
	}
	flag = 1;
	*db = ft_substr(*db, pos + 1, ft_strlen(*db) - (pos + 1), &flag);
	if (*db == NULL)
	{
		if (flag == 0)
		{
			ft_free(db);
			return (line);
		}
		ft_free(&line);
		return (NULL);
	}
	return (line);
}

char	*ft_readerr(ssize_t ret, char **db, char *buf)
{
	size_t	len;
	char	*line;
	int		pos;

	len = ft_strlen(*db);
	ft_free(&buf);
	if (len == 0)
	{
		ft_free(db);
		return (NULL);
	}
	if (ret == 0)
	{
		pos = ft_check_newline(*db);
		if (pos >= 0)
			line = ft_alloc_line(db, buf, pos);
		else
			line = ft_alloc_line(db, buf, (unsigned int)len - 1);
		if (line == NULL)
			return (NULL);
		return (line);
	}
	ft_free(db);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*db;
	char		*buf;
	ssize_t		ret;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > MAX_SIZE || fd > C_OPEN_MAX)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
	{
		ft_free(&db);
		return (NULL);
	}
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		db = ft_strjoin(db, buf);
		if (db == NULL)
			break ;
		if (ft_check_newline(db) >= 0)
			return (ft_alloc_line(&db, buf, ft_check_newline(db)));
	}
	return (ft_readerr(ret, &db, buf));
}
