#include "fdf.h"

void	scale_transform(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->matrix[i][j].vec->c[X] *= SCALE;
			map->matrix[i][j].vec->c[Y] *= SCALE;
			map->matrix[i][j].vec->c[Z] *= SCALE;
		}
	}
}

void	translate_transform(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->matrix[i][j].vec->c[X] += TRAN;
			map->matrix[i][j].vec->c[Y] += TRAN;
			map->matrix[i][j].vec->c[Z] += TRAN;
		}
	}
}

void	change_direction(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->matrix[i][j].vec->c[Y] *= -1;
		}
	}
}