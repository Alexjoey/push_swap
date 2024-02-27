/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:06:14 by amylle            #+#    #+#             */
/*   Updated: 2024/02/27 16:54:34 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

static int	checkint(char **argc)
{
	int		i;
	long	temp;

	i = 1;
	while (argc[i])
	{
		temp = ft_atol(argc[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

static int	checkduplicates(char **argc, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strncmp(argc[i], argc[j], 11) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	isstrnum(char **argc)
{
	int	i;
	int	j;

	i = 1;
	while (argc[i])
	{
		j = 0;
		if (argc[i][j] == '-')
			j++;
		while (argc[i][j])
		{
			if (!ft_isdigit(argc[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checkargs(int argv, char **argc)
{
	if (!isstrnum(argc))
		return (0);
	else if (checkduplicates(argc, argv))
		return (0);
	else if (checkint(argc))
		return (0);
	else
		return (1);
}
