/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:33:44 by rsarri-c          #+#    #+#             */
/*   Updated: 2023/01/08 12:32:54 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	free_all(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->nphilo)
	{
		pthread_detach(params->philo[i].thread);
		pthread_mutex_destroy(&params->philo[i].fork_l);
		pthread_mutex_destroy(params->philo[i].fork_r);
		i++;
	}
	free(params->philo);
	pthread_mutex_destroy(&params->print);
	pthread_mutex_destroy(&params->m_stop);
	pthread_mutex_destroy(&params->m_eat);
	pthread_mutex_destroy(&params->dead);
}

int	is_dead(t_params *params, int id)
{
	pthread_mutex_lock(&(params->dead));
	pthread_mutex_lock(&(params->m_stop));
	if (id)
		params->stop = 1;
	if (params->stop)
	{
		pthread_mutex_unlock(&(params->m_stop));
		pthread_mutex_unlock(&(params->dead));
		return (1);
	}
	pthread_mutex_unlock(&(params->m_stop));
	pthread_mutex_unlock(&(params->dead));
	return (0);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(t_params *params, int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep (params->nphilo);
}

void	print(t_philo *philo, char *str)
{
	long int	time;

	pthread_mutex_lock(&(philo->info->print));
	time = timestamp() - philo->info->t_start;
	if (!is_dead(philo->info, 0) && time >= 0 \
		&& time <= INT_MAX)
		printf("%lld %d %s", timestamp() - philo->info->t_start, philo->id, \
			str);
	pthread_mutex_unlock(&(philo->info->print));
}
