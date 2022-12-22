/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:34:32 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/12/22 22:58:09 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	leaks(void)
{
	system("leaks -q philo");
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			result;

	//atexit(leaks);
	if (argc != 5 && argc != 6)
		return (printf("Error\n"));
	result = ft_init(&params, argc, argv);
	if (result == 2)
		return (0);
	if (result)
	{
		free_all(&params);
		return (printf("Error\n"));
	}
	free_all(&params);
}
