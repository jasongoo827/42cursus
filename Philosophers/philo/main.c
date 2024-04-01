#include "philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 7)
		return (1);
	if (init_struct(&data, argc, argv) < 0)
		return (1);
	if (init_thread(&data) < 0)
		return (1);
	// free memory in data
}
