/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:42:34 by amylle            #+#    #+#             */
/*   Updated: 2024/03/01 16:31:06 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>
t_stack	*ft_makestack(int argv, char **argc)
{
	int		i;
	t_stack	*stack_a;
	long	temp;

	stack_a = NULL;
	i = 0;
	if (argv < 1)
		ft_error();
	else if (argv == 2)
	{
		argc[1] = ft_split(argc[1], ' ');
		if (!argc)
			ft_error();
		i--;
	}
	if (!ft_checkint(argc))
		ft_error();
	while (argc[++i])
	{
		temp = ft_atol(argc[i]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			ft_freestrarray(argc);
			ft_error();
		}
		ft_stackadd_back(&stack_a, ft_stacknew(temp));
	}
	return (stack_a);
}
