/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:30:35 by amylle            #+#    #+#             */
/*   Updated: 2024/02/27 17:03:15 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argv, char **argc)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argv > 1)
	{
		if (checkargs(argv, argc) == 0)
		{
			printf("error\n");
			return (0);
		}
		stack_a = ft_stacknew(ft_atoi(argc[i]));
		while (argc[++i])
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argc[i])));
		printstacks(stack_a, stack_b);
		ft_stackclear(&stack_a);
		ft_stackclear(&stack_b);
	}
	else
		printf("put in args pls\n");
}
