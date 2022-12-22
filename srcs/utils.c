/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:29:16 by rsarri-c          #+#    #+#             */
/*   Updated: 2022/12/20 15:41:27 by rsarri-c         ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tsize;
	void	*dst;

	tsize = count * size;
	dst = malloc(tsize);
	if (!(dst))
		return (0);
	ft_memset(dst, 0, tsize);
	return (dst);
}
