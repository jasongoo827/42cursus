/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:24:57 by jgoo              #+#    #+#             */
/*   Updated: 2023/10/21 13:24:58 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (dst[i] != '\0')
		i++;
	while (i < dstsize && src[j] != '\0')
		dst[i++] = src[j++];
	return (dst_len + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len;
	char		*ret;
	size_t		i;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
	{
		ft_free(&s1);
		return (NULL);
	}
	while (i <= len)
		ret[i++] = '\0';
	if (s1 != NULL)
		ft_strlcat(ret, s1, ft_strlen(s1));
	ft_strlcat(ret, s2, len + 1);
	ft_free(&s1);
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len, int *flag)
{
	size_t	i;
	char	*ret;
	size_t	j;

	i = 0;
	j = start;
	if (start >= ft_strlen(s))
	{
		*flag = 0;
		ft_free(&s);
		return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
	{
		ft_free(&s);
		return (NULL);
	}
	while (s[j] != '\0' && i < len)
		ret[i++] = s[j++];
	ret[i] = '\0';
	ft_free(&s);
	return (ret);
}

char	*ft_strdup(char *s1, unsigned int len)
{
	unsigned int	i;
	char			*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
