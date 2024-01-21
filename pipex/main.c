#include "pipex.h"

t_info	*init_info(int argc, char *argv[], char *envp[])
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	info->i_fd = open(argv[1], O_RDONLY);
	info->o_fd = open(argv[argc - 1], O_WRONLY);
	info->paths = get_cmd_path(argc, envp);
	info->cmds = get_cmd(info->paths, argc, argv);
	pipe(info->fd);
	return (info);
}

char	**get_cmd_path(int argc, char *envp[])
{
	char	**paths;
	int		i;

	paths = (char **)malloc(sizeof(char *) * argc);
	if (paths == NULL)
		exit(1);
	i = -1;
	while (envp[++i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
			return (paths);
		}
	}
	return (NULL);
}

char	**get_cmd(char **paths, int argc, char *argv[])
{
	char	**cmds;
	int		i;

	cmds = (char **)malloc(sizeof(char *) * (argc - 2));
	if (cmds == NULL)
		exit(1);
	i = -1;
	while (++i < argc - 3)
		cmds[i] = validate_access(paths, argv[i + 2]);
	cmds[i] = NULL;
	return (cmds);
}

char	*validate_access(char **paths, char *cmd)
{
	char	*path_cmd;
	char	*tmp;
	int		fd;
	int		i;

	fd = access(cmd, X_OK);
	if (fd != -1)
		return (cmd);
	i = -1;
	path_cmd = ft_strjoin("/", cmd);
	while (paths[++i] != NULL)
	{
		tmp = ft_strjoin(paths[i], path_cmd);
		fd = access(tmp, X_OK);
		if (fd != -1)
		{
			free(path_cmd);
			return (tmp);
		}
		close(fd);
		free(tmp);
	}
	free(path_cmd);
	return (NULL);
}

static void    sub_dup2(int zero, int first)
{
    dup2(zero, 0);
    dup2(first, 1);
}

static void		close_pipes(t_info *info)
{
	close(info->fd[0]);
	close(info->fd[1]);
}

void    child(t_info *info, char *argv[], char *envp[])
{
    info->pid = fork();
    if (info->pid != 0)
    {
        if (info->idx == 0)
            sub_dup2(info->i_fd, info->fd[1]);
        else if (info->idx == 1)
            sub_dup2(info->fd[0], info->o_fd);
        close_pipes(info);
        if (execve(info->cmds[info->idx], argv, envp) < 0)
            fprintf(stderr, "프로그램 실행 error: %s\n", strerror(errno));
    }
}

int main(int argc, char *argv[], char *envp[])
{
	t_info	*info;
	char 	**new_argv;

	info = init_info(argc, argv, envp);

	new_argv = (char **)malloc(sizeof(char *) * argc);

    /* command line으로 넘어온 parameter를 그대로 사용 */
    for(int idx = 0; idx < argc - 1; idx++) {
        new_argv[idx] = argv[idx + 1];
    }

    /* argc를 execve 파라미터에 전달할 수 없기 때문에 NULL이 파라미터의 끝을 의미함 */
    new_argv[argc - 1] = NULL;
	info->idx = -1;
    while (++(info->idx) < 1)
        child(info, new_argv, envp);
    close_pipes(info);
    waitpid(-1, NULL, 0);
    //parent_free(&info);

    
    return 0;
}