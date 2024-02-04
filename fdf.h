#ifndef FDF_H
# define FDF_H

# include "./Libft/libft/libft.h"
# include "./Libft/gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "mlx.h"

# define AERR "Invalid argument\n"
# define MERR "Memory allocation failed\n"
# define FERR "Filename extension error\n"
# define MAPERR "Map Error\n"
# define CPPPMAX 100
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define WIN_W 2560
# define WIN_H 1440
# define GAP 1
# define SCALE 50
# define TRAN 400

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef	struct s_vector
{
	double	c[4];
}	t_vector;

typedef struct s_vertex
{
	t_vector	*vec;
	int			color;
}	t_vertex;

typedef	struct s_lookat_matrix
{
	t_vector	*eye_position;
	t_vector	*eye_direction;
	t_vector	*up_direction;
	double		**matrix;
}	t_lookat_matrix;

typedef struct s_map
{
	int				width;
	int				height;
	t_vertex		**matrix;
	t_vertex		**back_up;
	t_lookat_matrix	*la_matrix;
}	t_map;

enum e_xyzw
{
	X = 0,
	Y,
	Z,
	W
};

// parse.c
t_map	*init_map(char *map);
void	read_fdf_file(t_map *map, int fd, char ***db);
void	check_width(t_map *map, char **strs);
void	init_matrix(t_map *map);
void	parse_matrix(t_map *map, char ***db);

// error.c
void	check_input_error(int argc, char *argv);
void	exit_error(char *s);
int		check_fdf(char *str);
void	check_error(int ret, int target);

// utils.c
void	free_db(t_map *map, char ***db);
void	print_matrix(t_map *map);
int		check_str_digit(char *str);
int		check_str_int(char *str);
void	dup_matrix(t_map *map);
void	alloc_lookat_matrix(t_map *map);
void	print_lookat(double **matrix);

// transform_matrix.c
void	transform_matrix(t_map *map);
void	calculate_matrix(t_map *map, double **matrix_ret);
void	calculate_vertex(t_vertex *v, double **matrix);
void	init_lookat_matrix(t_map *map, t_vector *r0, t_vector *r1, t_vector *r2);

// matrix_utils.c
void	scale_transform(t_map *map);
void	translate_transform(t_map *map);
void	change_direction(t_map *map);


// draw_image.c
int		create_argb(int a, int r, int g, int b);
void	put_pixel(t_image *img, int x, int y);
void	draw_image(t_image *img, t_map *map);
void	bresenham(int x0, int y0, int x1, int y1, t_image *img);

// vector.c
t_vector	*set_vector(double x, double y, double z, double w);
t_vector	*normalize_vector1(t_vector *vector);
void		normalize_vector2(t_vector *vector);
t_vector	*cross_vector(t_vector *v1, t_vector *v2);
double		dot_vector(t_vector *v1, t_vector *v2);
void		free_vector(t_vector *v);

# endif