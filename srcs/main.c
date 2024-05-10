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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_makestack(argv, argc);
	if (!stack_a || ft_checkduplicates(stack_a))
	{
		ft_stackclear(&stack_a);
		ft_error();
	}
	ft_threesort(&stack_a);
	printstacks(stack_a, stack_b);
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
}
