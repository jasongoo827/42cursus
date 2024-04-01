#include "philo.h"

void	ph_usleep(useconds_t time)
{
	LL	start_time;

	start_time = get_time();
	while (get_time() - start_time < time)
		usleep(time / 10);
}

LL	get_time()
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		return (-1);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

LL	ph_atoi(const char *str)
{
	int					i;
	unsigned long long	ret;
	int					sign;

	i = 0;
	ret = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret * sign);
}

int	ph_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}