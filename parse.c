#include "fdf.h"

t_map	*init_map(char *argv)
{
	t_map	*map;
	int		fd;
	char	***db;

	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		exit_error(MERR);
	map->width = 0;
	map->height = 0;
	db = (char ***)malloc(sizeof(char **) * CPPPMAX);
	if (db == NULL)
		exit_error(MERR);
	fd = open(argv, O_RDONLY);
	check_error(fd, -1);
	read_fdf_file(map, fd, db);
	init_matrix(map);
	parse_matrix(map, db);
	dup_matrix(map);
	alloc_lookat_matrix(map);
	free_db(map, db);
	check_error(close(fd), -1);
	return (map);
}

void	read_fdf_file(t_map *map, int fd, char ***db)
{
	char	*line;
	char	**strs;
	char	***tmp;

	tmp = db;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		strs = ft_split(line, ' ');
		check_width(map, strs);
		*tmp = strs;
		tmp++;
		map->height++;
		free(line);
	}
}

void	check_width(t_map *map, char **strs)
{
	int	i;
	int	width;

	i = -1;
	width = 0;
	while (strs[++i] != NULL && *strs[i] != '\n')
		width++;
	if (map->width == 0)
		map->width = width;
	else
	{
		if (map->width != width)
			exit_error(MAPERR);
	}
}

void	init_matrix(t_map *map)
{
	int	i;
	int	j;

	map->matrix = (t_vertex **)malloc(sizeof(t_vertex *) * (map->height));
	if (map->matrix == NULL)
		exit_error(MERR);
	i = -1;
	while (++i < map->height)
	{
		map->matrix[i] = (t_vertex *)malloc(sizeof(t_vertex) * (map->width));
		if (map->matrix[i] == NULL)
			exit_error(MERR);
		j = -1;
		while (++j < map->width)
		{
			map->matrix[i][j].vec = (t_vector *)malloc(sizeof(t_vector));
			if (map->matrix[i][j].vec == NULL)
				exit_error(MERR);
		}
	}
}

void	parse_matrix(t_map *map, char ***db)
{
	t_vertex	vertex;
	int			i;
	int			j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (db[i][++j] != NULL)
		{
			if (*db[i][j] == '\n')
				continue ;
			vertex = map->matrix[i][j];
			vertex.vec->c[X] = i * GAP;
			vertex.vec->c[Y] = j * GAP;
			// if (!check_str_digit(db[i][j]) || !check_str_int(db[i][j]))
			// 	exit_error(MAPERR);
			vertex.vec->c[Z] = (double)ft_atoi(db[i][j]) * GAP * 0.125;
			vertex.vec->c[W] = 1;
			// what if db[i][j] is not number ex) 1,0x0022
			// parse color if db[i][j] has ','
		}
	}
}