/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:42:34 by amylle            #+#    #+#             */
/*   Updated: 2024/03/19 15:14:36 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

static t_stack	*ft_makequotedstack(char **argc)
{
	int		i;
	t_stack	*stack_a;
	long	temp;

	if (!ft_checkint(argc))
		ft_freearrayerror(argc);
	stack_a = NULL;
	i = -1;
	while (argc[++i])
	{
		temp = ft_atol(argc[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			ft_freearrayerror(argc);
		ft_stackadd_back(&stack_a, ft_stacknew(temp));
	}
	ft_freestrarray(argc);
	return (stack_a);
}

t_stack	*ft_makestack(int argv, char **argc)
{
	int		i;
	t_stack	*stack_a;
	long	temp;

	i = -1;
	stack_a = NULL;
	if (argv == 1)
		exit (1);
	argc++;
	if (argv == 2)
	{
		argc = ft_split(argc[0], ' ');
		stack_a = ft_makequotedstack(argc);
		return (stack_a);
	}
	if (!ft_checkint(argc))
		ft_error();
	while (argc[++i])
	{
		temp = ft_atol(argc[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			ft_error();
		ft_stackadd_back(&stack_a, ft_stacknew(temp));
	}
	return (stack_a);
}
