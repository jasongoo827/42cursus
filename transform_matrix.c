#include "fdf.h"

void	transform_matrix(t_map *map)
{
	t_vector	*r0;
	t_vector	*r1;
	t_vector	*r2;

	// R2 normalize eye direction
	r2 = normalize_vector1(map->la_matrix->eye_direction);
	// R0 - cross R2 X up direction
	r0 = cross_vector(r2, map->la_matrix->up_direction);
	// normalize R0
	normalize_vector2(r0);
	// R1 - cross R2 X R0
	r1 = cross_vector(r2, r0);
	// normalize R1
	normalize_vector2(r1);
	// get lookat_matrix
	init_lookat_matrix(map, r0, r1, r2);
	// do view transform (lookat_matrix && every (x,y,z,1))
	calculate_matrix(map, map->la_matrix->matrix);
	//change direction
	change_direction(map);
	// scale transform
	scale_transform(map);
	// translate transform
	translate_transform(map);
	// free vectors
	free(r0);
	free(r1);
	free(r2);
}

void	init_lookat_matrix(t_map *map, t_vector *r0, t_vector *r1, t_vector *r2)
{
	double		d0;
	double		d1;
	double		d2;
	double		**matrix;

	d0 = dot_vector(map->la_matrix->eye_position, r0);
	d1 = dot_vector(map->la_matrix->eye_position, r1);
	d2 = dot_vector(map->la_matrix->eye_position, r2);
	matrix = map->la_matrix->matrix;
	matrix[0][0] = r0->c[X];
	matrix[1][0] = r0->c[Y];
	matrix[2][0] = r0->c[Z];
	matrix[0][1] = r1->c[X];
	matrix[1][1] = r1->c[Y];
	matrix[2][1] = r1->c[Z];
	matrix[0][2] = r2->c[X];
	matrix[1][2] = r2->c[Y];
	matrix[2][2] = r2->c[Z];
	matrix[0][3] = 0;
	matrix[1][3] = 0;
	matrix[2][3] = 0;
	matrix[3][0] = d0;
	matrix[3][1] = d1;
	matrix[3][2] = d2;
	matrix[3][3] = 1;
}

void	calculate_matrix(t_map *map, double **matrix_ret)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
			calculate_vertex(&map->matrix[i][j], matrix_ret);
	}
}

void	calculate_vertex(t_vertex *v, double **matrix)
{
	int	x;
	int	y;
	int	z;
	int	w;

	x = v->vec->c[X];
	y = v->vec->c[Y];
	z = v->vec->c[Z];
	w = v->vec->c[W];
	v->vec->c[X] = matrix[0][0] * x + matrix[0][1] * \
	y + matrix[0][2] * z + matrix[0][3] * w;
	v->vec->c[Y] = matrix[1][0] * x + matrix[1][1] * \
	y + matrix[1][2] * z + matrix[1][3] * w;
	v->vec->c[Z] = matrix[2][0] * x + matrix[2][1] * \
	y + matrix[2][2] * z + matrix[2][3] * w;
	v->vec->c[W] = matrix[3][0] * x + matrix[3][1] * \
	y + matrix[3][2] * z + matrix[3][3] * w;
	if (v->vec->c[W] > 1)
	{
		v->vec->c[X] /= v->vec->c[W];
		v->vec->c[Y] /= v->vec->c[W];
		v->vec->c[Z] /= v->vec->c[W];
		v->vec->c[W] /= v->vec->c[W];
	}
}