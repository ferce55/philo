/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:16 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/11/30 15:01:08 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static size_t	ft_lenght(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	len;
	int	num;
	int	i;

	i = 0;
	num = 0;
	len = ft_lenght(str);
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
