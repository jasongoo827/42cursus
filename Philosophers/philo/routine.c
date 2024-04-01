#include "philo.h"

void	*monitor(void *ptr)
{
	t_philo	*philo;

	philo  = (t_philo *)ptr;
	// pthread_mutex_lock(&philo->data->read);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->data->lock);
		if (philo->data->fininshed >= philo->data->philo_num)
			philo->data->dead = 1;
		pthread_mutex_unlock(&philo->data->lock);
	}
	// pthread_mutex_unlock(&philo->data->read);
	return (NULL);
}

void	*master(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	// pthread_mutex_lock(&philo->data->read);
	while (philo->data->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() > philo->time_to_die && philo->eating == 0)
			message(philo, "died");
		if (philo->eat_cnt == philo->data->must_eat_num)
		{
			pthread_mutex_lock(&philo->data->lock);
			philo->data->fininshed++;
			philo->eat_cnt++;
			pthread_mutex_unlock(&philo->data->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	// pthread_mutex_unlock(&philo->data->read);
	return (NULL);
}

void	*routine(void *ptr)
{
	t_philo	*philo;
	
	philo = (t_philo *)ptr;
	philo->time_to_die = philo->data->death_time + get_time();
	if (pthread_create(&philo->t, NULL, master, philo) < 0)
		return ((void *)-1);
	while (philo->data->dead == 0)
	{
		eat(philo);
		message(philo, "is thinking");
	}
	// check pthread join error
	pthread_join(philo->t, NULL);
	return (NULL);
}


int	init_thread(t_data *data)
{
	pthread_t	monitor_t;
	int	i;

	data->start_time = get_time();
	if (data->must_eat_num > 0)
	{
		if (pthread_create(&monitor_t, NULL, monitor, &data->philos[0]) < 0)
			return (-1);
	}
	i = -1;
	while (++i < data->philo_num)
	{
		if (pthread_create(&data->tid[i], NULL, routine, &data->philos[i]) < 0)
			return (-1);
		ph_usleep(1);
	}
	i = -1;
	while (++i < data->philo_num)
		pthread_join(data->tid[i], NULL);
	return (0);
}