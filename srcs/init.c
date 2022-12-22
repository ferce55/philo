/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:47:20 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/12/22 22:49:40 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static pthread_mutex_t	*asing_fork(t_params *params, int i)
{
	if (i == params->nphilo - 1)
		return (&params->philo[0].fork_l);
	return (&params->philo[i + 1].fork_l);
}	

static int	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_is_digit(argv[i][j]) != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	init_philos(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->nphilo)
	{
		params->philo[i].id = i + 1;
		params->philo[i].m_count = 0;
		params->philo[i].is_eating = 0;
		params->philo[i].info = params;
		params->philo[i].last_eat = timestamp();
		pthread_mutex_init(&(params->philo[i].fork_l), NULL);
		params->philo[i].fork_r = asing_fork(params, i);
		if (pthread_create(&params->philo[i].thread, NULL, \
				&philo_life, &(params->philo[i])) != 0)
			return (1);
	}
	i = 0;
	check_death(params);
	while (i < params->nphilo)
	{
		if (pthread_join(params->philo[i].thread, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init(t_params *params, int argc, char **argv)
{
	if (check_argv(argv) != 0)
		return (1);
	pthread_mutex_init(&params->print, NULL);
	pthread_mutex_init(&params->m_stop, NULL);
	pthread_mutex_init(&params->m_eat, NULL);
	pthread_mutex_init(&params->dead, NULL);
	params->stop = 0;
	params->nphilo = ft_atoi(argv[1]);
	params->t_todie = ft_atoi(argv[2]);
	params->t_toeat = ft_atoi(argv[3]);
	params->t_tosleep = ft_atoi(argv[4]);
	params->n_eattimes = -1;
	if (argc == 6)
		params->n_eattimes = ft_atoi(argv[5]);
	if (argc == 6 && params->n_eattimes == 0)
		return (2);
	params->philo = ft_calloc(params->nphilo, sizeof(t_philo));
	if (!params->philo)
		return (1);
	params->t_start = timestamp();
	init_philos(params);
	return (0);
}
