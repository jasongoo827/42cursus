/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:25:06 by jgoo              #+#    #+#             */
/*   Updated: 2023/10/21 13:49:44 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define MAX_SIZE 9223372036854775807
# define C_OPEN_MAX 49152

char	*get_next_line(int fd);
int		ft_check_newline(char *str);
char	*ft_alloc_line(char **db, char *buf, unsigned int pos);
char	*ft_readerr(ssize_t ret, char **db, char *buf);
void	ft_free(char **buf);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len, int *flag);
char	*ft_strdup(char *s1, unsigned int len);

#endif
