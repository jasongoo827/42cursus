#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define MAXINT 2147483647
# define INVALID "Invalid input\n"
# define MALLOC_ERR "Memory Allocation failed\n"
# define TH_ERR "Creating Thread failed\n"

typedef long long LL;
typedef struct s_data t_data;

typedef struct s_philo
{
	t_data			*data;
	LL				time_to_die;
	LL				eat_cnt;
	int				idx;
	int				eating;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	lock;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	LL				philo_num;
	LL				death_time;
	LL				eat_time;
	LL				sleep_time;
	LL				must_eat_num;
	LL				start_time;
	int				dead;
	int				fininshed;
	pthread_t		monitor_t;
	pthread_t		master_t;
	pthread_mutex_t	start;
	pthread_mutex_t	write;
	pthread_mutex_t	lock;
}	t_data;

// main.c
void	free_memory(t_data *data);
void	ph_exit(t_data *data);

// init_struct.c
int		init_struct(t_data *data, int argc, char *argv[]);

// essentials.c
int		check_death(t_data *data);
void	message(t_philo *philo, char *str);
void	eat(t_philo *philo);

// utils.c
LL		ph_atoi(const char *str);
LL		get_time();
void	ph_usleep(useconds_t time);
int		ph_strncmp(const char *s1, const char *s2, size_t n);
int		error(t_data *data, char *str);

// utils2.c
size_t	ph_strlen(const char *str);

// routine.c
int		init_thread(t_data *data);
int		case_one(t_data *data);


#endif
