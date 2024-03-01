/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:42:34 by amylle            #+#    #+#             */
/*   Updated: 2024/02/29 15:48:46 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_makestack(int argv, char **argc)
{
	int		i;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 0;
	if (argv < 1)
		ft_error();
	else if (argv == 2)
	{
		argc = ft_split(argc[1], ' ');
		if (!argc)
			ft_error();
		while (argc[i])
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atol(argc[i++])));
	}
	else
		while (argc[++i])
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atol(argc[i])));
	return (stack_a);
}
