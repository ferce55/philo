/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:43:00 by rsarri-c          #+#    #+#             */
/*   Updated: 2023/01/08 11:55:12 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				m_count;
	int				is_eating;
	pthread_t		thread;
	long int		last_eat;
	struct s_params	*info;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	fork_l;
	pthread_mutex_t	m_last_eat;
}	t_philo;

typedef struct s_params
{
	int				eat;
	int				nphilo;
	int				t_todie;
	int				t_toeat;
	int				t_tosleep;
	int				n_eattimes;
	int				stop;
	long int		t_start;
	t_philo			*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	m_stop;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	dead;
}	t_params;

int			ft_init(t_params *params, int argc, char **argv);
int			ft_is_digit(char c);
int			ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
long long	timestamp(void);
void		*philo_life(void *philo_aux);
void		ft_usleep(t_params *params, int ms);
int			is_dead(t_params *params, int id);
void		print(t_philo *philo, char *str);
void		free_all(t_params *params);
void		*check_death(t_params *params);
#endif