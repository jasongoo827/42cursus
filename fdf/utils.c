#include "fdf.h"

void	free_db(t_map *map, char ***db)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (db[i][++j] != NULL)
			free(db[i][j]);
		free(db[i]);
	}
	free(db);
}

void	print_matrix(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			// if ((int)map->back_up[i][j].vec->c[Z] != 0)
			// 	printf("(x: %lf, y: %lf) ", map->matrix[i][j].vec->c[0], \
			// 	map->matrix[i][j].vec->c[1]);
			printf("(x: %lf, y: %lf) ", map->matrix[i][j].vec->c[0], \
			map->matrix[i][j].vec->c[1]);
		}
		printf("\n");
	}
}

void	print_lookat(double **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%lf ", matrix[i][j]);
		printf("\n");
	}
}

int	check_str_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[0] == '-')
	{
		if (str[1] == '\0')
			return (0);
		while (str[++i] != '\0')
		{
			if (ft_isdigit(str[i] - '0') == 0)
				return (0);
		}
		return (1);
	}
	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_isdigit(str[i] - '0') == 0)
			return (0);
	}
	return (1);
}

int	check_str_int(char *str)
{
	int			i;
	long long	ret;
	int			sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (ret * sign > (long long)MAX_INT || ret * sign < (long long)MIN_INT)
		return (0);
	return (1);
}

void	dup_matrix(t_map *map)
{
	int	i;
	int	j;

	map->back_up = (t_vertex **)malloc(sizeof(t_vertex *) * (map->height));
	if (map->back_up == NULL)
		exit_error(MERR);
	i = -1;
	while (++i < map->height)
	{
		map->back_up[i] = (t_vertex *)malloc(sizeof(t_vertex) * (map->width));
		if (map->matrix[i] == NULL)
			exit_error(MERR);
		j = -1;
		while (++j < map->width)
		{
			map->back_up[i][j].vec = (t_vector *)malloc(sizeof(t_vector));
			if (map->back_up[i][j].vec == NULL)
				exit_error(MERR);
			map->back_up[i][j].vec->c[0] = map->matrix[i][j].vec->c[0];
			map->back_up[i][j].vec->c[1] = map->matrix[i][j].vec->c[1];
			map->back_up[i][j].vec->c[2] = map->matrix[i][j].vec->c[2];
			map->back_up[i][j].vec->c[3] = map->matrix[i][j].vec->c[3];
			map->back_up[i][j].color = map->matrix[i][j].color;
		}
	}
}

void	alloc_lookat_matrix(t_map *map)
{
	int	i;

	map->la_matrix = (t_lookat_matrix *)malloc(sizeof(t_lookat_matrix));
	if (map->la_matrix == NULL)
		exit_error(MERR);
	map->la_matrix->eye_position = set_vector(1, 1, -1, 1);
	map->la_matrix->eye_direction = set_vector(-1, -1, 1, 0);
	map->la_matrix->up_direction = set_vector(0, 1, 0, 0);
	map->la_matrix->matrix = (double **)malloc(sizeof(double *) * 4);
	if (map->la_matrix->matrix == NULL)
		exit_error(MERR);
	i = -1;
	while (++i < 4)
	{
		map->la_matrix->matrix[i] = (double *)malloc(sizeof(double) * 4);
		if (map->la_matrix->matrix[i] == NULL)
			exit_error(MERR);
	}
}