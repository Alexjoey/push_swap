/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:10:54 by amylle            #+#    #+#             */
/*   Updated: 2024/02/28 13:13:27 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_input_error(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	if (ft_isinputint(argv) == false)
		ft_error ();
}

bool	ft_isinputint(char **argc)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (argc[++i])
	{
		j = 0;
		if (argc[i][j] == '+' || argc[i][j] == '-')
			j++;
		while (argc[i][j] >= '0' && argc[i][j] <= '9')
			j++;
		if (argc[i][j] != '\0')
			return (false);
		temp = ft_atol(argc[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (false);
	}
	return (true);
}

int	ft_checkduplicates(t_stack *stack_a)
{
	t_stack	*check;

	while (stack_a && stack_a->next)
	{
		check = stack_a->next;
		while (check)
		{
			if (stack_a->content == check->content)
				return (1);
			check = check->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
