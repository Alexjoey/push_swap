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

    ft_input_error(argv, argc);
	stacks = ft_initstacks(argc);
	if (!stacks->a || ft_checkduplicates(stacks->a))
	{
		ft_clearall(stacks);
		ft_error();
	}
    ft_sort(stacks);
	printstacks(stacks);
	ft_clearall(stacks);
}
