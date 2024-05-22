/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinputerrors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:51 by amylle            #+#    #+#             */
/*   Updated: 2024/05/22 16:33:52 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_input_error(int argc, char **argv)
{
	if (argc == 1)
		exit (0);
	if (ft_isinputint(argv) == false)
	{
		if (argc == 2)
			ft_freestrarray(argv);
		ft_error ();
	}
}

bool	ft_isinputint(char **argc)
{
	int		i;
	int		j;
	long	temp;

	i = -1;
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
