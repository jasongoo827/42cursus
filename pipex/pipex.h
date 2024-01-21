#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_info
{
    pid_t   pid;
    int     o_fd;
    int     i_fd;
    int     idx;
    int     fd[2];
    char    **paths;
    char    **cmds;
}   t_info;

t_info	*init_info(int argc, char *argv[], char *envp[]);
char	**get_cmd_path(int argc, char *envp[]);
char	**get_cmd(char **paths, int argc, char *argv[]);
char	*validate_access(char **paths, char *cmd);


char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

# endif