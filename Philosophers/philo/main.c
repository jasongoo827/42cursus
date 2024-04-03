#include "philo.h"

void	free_memory(t_data *data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	ph_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->start);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	free_memory(data);
}

void	*one_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	philo->time_to_die = philo->data->death_time + get_time();
	message(philo, "has taken a fork");
	ph_usleep(philo->data->death_time);
	if (get_time() >= philo->time_to_die)
		message(philo, "died");
	return (NULL);
}

int	case_one(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, one_routine, &data->philos[0]) < 0)
		return (1);
	pthread_join(data->tid[0], NULL);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 5 || argc > 7)
		return (1);
	if (init_struct(&data, argc, argv) < 0)
		return (1);
	if (data.philo_num == 1)
		return (case_one(&data));
	if (init_thread(&data) < 0)
		return (1);
	ph_exit(&data);
}
