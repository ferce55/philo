/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:34:32 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/11/30 11:47:02 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc != 5 && argc != 6)
		return (printf("Error\n"));
	if (ft_init(&params, argc, argv))
		return (printf("Error\n"));
}
