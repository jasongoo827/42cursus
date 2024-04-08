#include "fdf.h"

// void check_leak()
// {
// 	system("leaks fdf");
// }



int main(int argc, char *argv[])
{
	t_map	*map;

	check_input_error(argc, argv[1]);
	map = init_map(argv[1]);
	transform_matrix(map);
	// print_matrix(map);

	t_image	image;
	void	*mlx_ptr;
	void	*win_ptr;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "Hello World!");
	
	// put pixel
	image.img_ptr = mlx_new_image(mlx_ptr, WIN_W, WIN_H);
	image.bits_per_pixel = 0;
	image.size_line = 0;
	image.endian = 0;
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel, \
	&image.size_line, &image.endian);

	draw_image(&image, map);


	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img_ptr, 1000, 0);
	mlx_loop(mlx_ptr);

	return (0);
}