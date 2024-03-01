/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:42:34 by amylle            #+#    #+#             */
/*   Updated: 2024/03/01 16:59:31 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

t_stack	*ft_makestack(int argv, char **argc)
{
	int		i;
	t_stack	*stack_a;
	long	temp;

	i = -1;
	stack_a = NULL;
	if (argv < 1)
		ft_error();
	argc++;
	if (argv == 2)
		argc = ft_split(argc[0], ' ');
	if (!argc || !ft_checkint(argc))
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
