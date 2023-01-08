/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:34:32 by rsarri-c          #+#    #+#             */
/*   Updated: 2023/01/08 21:23:43 by rsarri-c         ###   ########.fr       */
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
