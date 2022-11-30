/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:47:20 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/11/30 15:00:57 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
	printf("%d\n", params->nphilo);
	params->t_todie = ft_atoi(argv[2]);
	printf("%d\n", params->t_todie);
	params->t_toeat = ft_atoi(argv[3]);
	printf("%d\n", params->t_toeat);
	params->t_tosleep = ft_atoi(argv[4]);
	printf("%d\n", params->t_tosleep);
	if (argc == 6)
	{
		params->n_eattimes = ft_atoi(argv[5]);
		printf("%d", params->n_eattimes);
	}
	params->philo = malloc(sizeof(t_philo) * 0);
	return (0);
}
