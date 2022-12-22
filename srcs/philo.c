/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:50:45 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/12/22 23:10:40 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*check_death(t_params *params)
{
	int	i;

	pthread_mutex_lock(&params->m_stop);
	while (params->stop != 1)
	{
		pthread_mutex_unlock(&params->m_stop);
		i = 0;
		while (i < params->nphilo)
		{
			pthread_mutex_lock(&params->m_eat);
			if ((long)params->t_todie <= (timestamp() \
				- params->philo[i].last_eat))
			{
				pthread_mutex_lock(&params->m_stop);
				print(&(params->philo[i]), " died\n");
				params->stop = 1;
				pthread_detach(params->philo[i].thread);
				pthread_mutex_unlock(&params->m_stop);
			}
			pthread_mutex_unlock(&params->m_eat);
			i++;
		}
		pthread_mutex_lock(&params->m_stop);
	}
	return (NULL);
}

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->fork_l));
	print(philo, " has taken a fork\n");
	if (philo->info->nphilo == 1)
	{
		ft_usleep(philo->info, philo->info->t_todie * 2);
		return ;
	}
	pthread_mutex_lock(philo->fork_r);
	print(philo, " has taken a fork\n");
}

void	philo_eat(t_philo *philo)
{
	print(philo, " is eating\n");
	pthread_mutex_lock(&(philo->info->m_eat));
	philo->last_eat = timestamp();
	philo->m_count++;
	pthread_mutex_unlock(&(philo->info->m_eat));
	ft_usleep(philo->info, philo->info->t_toeat);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(&(philo->fork_l));
	print(philo, " is sleeping\n");
	ft_usleep(philo->info, philo->info->t_tosleep);
	print(philo, " is thinking\n");
}

void	*philo_life(void *philo_aux)
{
	t_philo		*philo;

	philo = (t_philo *)philo_aux;
	if (philo->id % 2 == 0)
		ft_usleep(philo->info, philo->info->t_toeat);
	while (!is_dead(philo, 0))
	{
		take_fork(philo);
		philo_eat(philo);
		if (philo->m_count == philo->info->n_eattimes)
		{
			pthread_mutex_lock(&philo->info->m_stop);
			if (++philo->info->eat == philo->info->nphilo)
			{
				pthread_mutex_unlock(&philo->info->m_stop);
				is_dead(philo, 1);
			}
			pthread_mutex_unlock(&philo->info->m_stop);
			return (NULL);
		}
	}
	return (NULL);
}
