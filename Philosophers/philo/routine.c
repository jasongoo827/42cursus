#include "philo.h"

void	*monitor(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (1)
	{
		if (check_death(data) < 0)
			return (NULL);
		pthread_mutex_lock(&data->lock);
		if (data->fininshed >= data->philo_num)
			data->dead = 1;
		pthread_mutex_unlock(&data->lock);
	}
	return (NULL);
}

void	*master(void *ptr)
{
	t_data	*data;
	int		i;

	data = (t_data *)ptr;
	i = -1;
	pthread_mutex_lock(&data->start);
	pthread_mutex_unlock(&data->start);
	// ph_usleep(1000);
	while (++i < data->philo_num)
	{
		ph_usleep(200);
		if (check_death(data) < 0)
			return (NULL);
		pthread_mutex_lock(&data->philos[i].lock);
		if (get_time() >= data->philos[i].time_to_die && data->philos[i].eating == 0)
			message(&data->philos[i], "died");
		pthread_mutex_unlock(&data->philos[i].lock);
	}
	return (NULL);
}

void	*routine(void *ptr)
{
	t_philo	*philo;
	
	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	// ph_usleep(100);
	if ((philo->idx & 1) == 0)
		ph_usleep(100);
	philo->time_to_die = philo->data->death_time + get_time();
	while (1)
	{
		if (check_death(philo->data) < 0)
			return (NULL);
		eat(philo);
		message(philo, "is thinking");
		if (philo->eat_cnt == philo->data->must_eat_num)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->fininshed++;
			pthread_mutex_unlock(&philo->data->lock);
		}
	}
	return (NULL);
}

int	init_thread(t_data *data)
{
	int	i;

	data->start_time = get_time();
	pthread_mutex_lock(&data->start);
	i = -1;
	if (data->must_eat_num > 0)
	{
		if (pthread_create(&data->monitor_t, NULL, monitor, data) < 0)
			return (error(data, TH_ERR));
	}
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, routine, &data->philos[i]) < 0)
			return (error(data, TH_ERR));
		ph_usleep(1);
	}
	if (pthread_create(&data->master_t, NULL, master, data) < 0)
		return (error(data, TH_ERR));
	pthread_mutex_unlock(&data->start);
	i = -1;
	while (++i < data->philo_num)
		pthread_join(data->tid[i], NULL);
	pthread_join(data->monitor_t, NULL);
	pthread_join(data->master_t, NULL);
	return (0);
}
