/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoo <jgoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:00:43 by jgoo              #+#    #+#             */
/*   Updated: 2023/11/04 17:00:44 by jgoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define MAX_SIZE 9223372036854775807
# define C_OPEN_MAX 49152

typedef struct s_list
{
	char			*buf;
	int				fd;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
t_list	*ft_getfd(t_list *lst, int fd);
t_list	*ft_lstnew(t_list **head, t_list *lst, int fd);
char	*read_file(t_list *node, int fd);
char	*ft_getline(char *buf);
void	remove_lst(t_list **lst, t_list *node, int fd);
char	*ft_substr(char *buf);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *str, char c);
size_t	ft_strlen(char *str);

#endif
