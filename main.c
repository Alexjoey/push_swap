/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:30:35 by amylle            #+#    #+#             */
/*   Updated: 2024/03/19 15:42:30 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argv, char **argc)
{
	t_stacks	*stacks;
	char		**array;

	if (argv == 2)
	{
		array = ft_split(argc[1], ' ');
		ft_input_error(argv, array);
		stacks = ft_initstacks(argv, array);
		ft_freestrarray(array);
	}
	else
	{
		ft_input_error(argv, ++argc);
		stacks = ft_initstacks(argv, argc);
	}
	if (!stacks->a || ft_checkduplicates(stacks->a))
	{
		ft_clearall(stacks);
		ft_error();
	}
	ft_sort(stacks);
	ft_clearall(stacks);
}
