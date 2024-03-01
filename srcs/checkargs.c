/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:06:14 by amylle            #+#    #+#             */
/*   Updated: 2024/03/01 16:20:45 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int	ft_checkint(char **argc)
{
	int	i;
	int j;

	i = 0;
	while (argc[++i])
	{
		j = 0;
		while (argc[i][j] && \
				((argc[i][j] >= 9 && argc[i][j] <=13) || argc[i][j] == 32))
			j++;
		if (argc[i][j] == '=' || argc[i][j] == '-')
			j++;
		while (argc[i][j] >= '0' && argc[i][j] <= '9')
			j++;
		if (argc[i][j] != '\0')
			return (0);
	}
	return (1);
}

int	ft_checkduplicates(t_stack *stack_a)
{
	t_stack	*check;

	while (stack_a && stack_a->next)
	{
		check = stack_a->next;
		while (check)
		{
			if(stack_a->content == check->content)
				return (1);
			check = check->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
