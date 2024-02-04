#include "fdf.h"

void	exit_error(char *s)
{
	check_error(write(2, s, ft_strlen(s)), -1);
	exit(1);
}

void	check_error(int ret, int target)
{
	if (ret == target)
	{
		check_error(write(2, strerror(errno), ft_strlen(strerror(errno))), -1);
		exit(0);
	}
}

void	check_input_error(int argc, char *argv)
{
	if (argc != 2)
		exit_error(AERR);
	if (check_fdf(argv) == 0)
		exit_error(FERR);
}

int	check_fdf(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_strncmp(str + i, ".fdf", 4) == 0)
			return (1);
	}
	return (0);
}