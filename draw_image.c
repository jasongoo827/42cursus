#include "fdf.h"

int		create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	put_pixel(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + y * img->size_line + x * (img->bits_per_pixel / 8);
	*(int *)dst = create_argb(0, 255, 255, 255);
}

void	draw_image(t_image *img, t_map *map)
{
	int		i;
	int		j;
	t_vertex	cur;
	t_vertex	next;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j + 1 < map->width)
			{
				cur = map->matrix[i][j];
				next = map->matrix[i][j + 1];
				bresenham(cur.vec->c[X], cur.vec->c[Y], next.vec->c[X], next.vec->c[Y], img);
			}
			if (i + 1 < map->height)
			{
				cur = map->matrix[i][j];
				next = map->matrix[i + 1][j];
				bresenham(cur.vec->c[X], cur.vec->c[Y], next.vec->c[X], next.vec->c[Y], img);
			}
		}
	}
}

void	bresenham(int x0, int y0, int x1, int y1, t_image *img)
{
	int	dx = abs(x1 - x0);
	int	dy = abs(y1 - y0);
    int	p = 2 * dy - dx;
    int	twoDy = 2 * dy;
	int	twoDyMinusDx = 2 * (dy - dx);
	int	x;
	int	y;
	
	if (x0 > x1) 
	{
		x = x1;
		y = y1;
		x1 = x0;
	}
	else
	{
		x = x0;
		y = y0; 
	}
	put_pixel(img, x, y);
  	while (x < x1)
	{
		x++;
    	if (p < 0)
			p += twoDy;
		else
		{ 
			y++;
			p += twoDyMinusDx;
    	}
    	put_pixel(img, x, y);
	}
}