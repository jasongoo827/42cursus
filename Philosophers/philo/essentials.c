#include "philo.h"

int	check_death(t_data *data)
{
	pthread_mutex_lock(&data->lock);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->lock);
		return (-1);
	}
	else
	{
		pthread_mutex_unlock(&data->lock);
		return (0);
	}
}

void	message(t_philo *philo, char *str)
{
	LL	time;

	pthread_mutex_lock(&philo->data->write);
	time = get_time() - philo->data->start_time;
	if (ph_strncmp(str, "died", 5) == 0 && philo->data->dead == 0)
	{
		philo->data->dead = 1;
		printf("%lld %d died\n", time, philo->idx);
	}
	if (philo->data->dead == 0)
		printf("%lld %d %s\n", time, philo->idx, str);
	pthread_mutex_unlock(&philo->data->write);
}

void	take_fork(t_philo *philo)
{
	if (philo->idx & 1)
	{
		pthread_mutex_lock(philo->r_fork);
		message(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		message(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		message(philo, "has taken a fork");
	}
}

void	drop_fork(t_philo *philo)
{
	if (philo->idx & 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		message(philo, "is sleeping");
		ph_usleep(philo->data->sleep_time);
	}
	else
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		message(philo, "is sleeping");
		ph_usleep(philo->data->sleep_time);
	}
}

void	eat(t_philo *philo)
{
	take_fork(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->data->death_time;
	message(philo, "is eating");
	philo->eat_cnt++;
	ph_usleep(philo->data->eat_time);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_fork(philo);
}
