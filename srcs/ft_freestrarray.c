/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:26:56 by amylle            #+#    #+#             */
/*   Updated: 2024/03/19 15:08:00 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freearrayerror(char **array)
{
	ft_freestrarray(array);
	ft_error();
}

void	ft_freestrarray(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		free (array[i]);
	free (array);
	return ;
}
