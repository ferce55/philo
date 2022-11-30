/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:43:00 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/11/30 11:48:47 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	int				id;
	int				m_count;
	int				is_eating;
	pthread_t		thread;
	long int		last_eat;
	struct t_params	*info;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
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

int	ft_init(t_params *params, int argc, char **argv);
int	ft_is_digit(char c);
int	ft_atoi(char *str);
#endif