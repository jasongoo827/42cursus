#include <mlx.h>

int main()
{
	void	*mlx_ptr;
	void	*win_ptr; // 생성할 윈도우를 가리키는 포인터
	
	mlx_ptr = mlx_init();	
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello World!"); 
	mlx_loop(mlx_ptr); // loop를 돌면서 event를 기다리고, 생성한 윈도우를 Rendering한다. 
	return (0);
}