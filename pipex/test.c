#include "pipex.h"



int main(int argc, char *argv[], char *envp[])
{
	char **new_argv;
    int  idx;

    new_argv = (char **)malloc(sizeof(char *) * argc);

    int	i;
	i = -1;
	(void)argc;
	(void)argv;
	char	**paths;
	while (envp[++i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[i] + 5, ':');
		}
	}

    /* command line으로 넘어온 parameter를 그대로 사용 */
    for(idx = 0; idx < argc - 1; idx++) {
        new_argv[idx] = argv[idx + 1];
    }

    /* argc를 execve 파라미터에 전달할 수 없기 때문에 NULL이 파라미터의 끝을 의미함 */
    new_argv[argc - 1] = NULL;
	i = -1;
	while (paths[++i] != NULL)
	{
		char *tmp = ft_strjoin(paths[i], "/");
		char *p = ft_strjoin(tmp, new_argv[0]);
		printf("%s\n", p);
		if (execve(p, new_argv, envp) == -1) {
			fprintf(stderr, "프로그램 실행 error: %s\n", strerror(errno));
		}
		free(p);
		free(tmp);
	}

    
    return 0;
}