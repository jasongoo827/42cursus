#include "philo.h"

static int	init_data(t_data *data, int argc, char *argv[])
{
	data->philo_num = ph_atoi(argv[1]);
	data->death_time = ph_atoi(argv[2]);
	data->eat_time = ph_atoi(argv[3]);
	data->sleep_time = ph_atoi(argv[4]);
	if (argc == 6 && ph_atoi(argv[5]) > 0)
		data->must_eat_num = ph_atoi(argv[5]);
	else
		data->must_eat_num = -1;
	if (data->philo_num <= 0 || data->philo_num > MAXINT || data->death_time < 0 \
	|| data->death_time > MAXINT || data->eat_time < 0 || data->eat_time > MAXINT\
	|| data->sleep_time < 0 || data->sleep_time > MAXINT)
		return (error(NULL, INVALID));
	pthread_mutex_init(&data->start, NULL);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	data->dead = 0;
	data->fininshed = 0;
	return (0);
}

static int	alloc_data(t_data *data)
{
	data->tid = (pthread_t *)malloc(sizeof(pthread_t) * data->philo_num);
	if (data->tid == NULL)
		return (error(data, MALLOC_ERR));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_num);
	if (data->forks == NULL)
		return (error(data, MALLOC_ERR));
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_num);
	if (data->philos == NULL)
		return (error(data, MALLOC_ERR));
	return (0);
}

static void	init_fork(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	data->philos[0].l_fork = &data->forks[0];
	data->philos[0].r_fork = &data->forks[data->philo_num - 1];
	i = 0;
	while (++i < data->philo_num)
	{
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[i - 1];
	}
}

static void	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].idx = i + 1;
		data->philos[i].eat_cnt = 0;
		data->philos[i].eating = 0;
		pthread_mutex_init(&data->philos[i].lock, NULL);
	}
}

int	init_struct(t_data *data, int argc, char *argv[])
{
	if (init_data(data, argc, argv) < 0)
		return (-1);
	if (alloc_data(data) < 0)
		return (-1);
	init_fork(data);
	init_philos(data);
	return (0);
}
