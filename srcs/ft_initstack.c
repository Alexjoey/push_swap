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

t_stacks	*ft_initstacks(int argv, char **array)
{
	int			i;
	t_stacks	*stacks;
	t_stack		*new;

	new = NULL;
	stacks = ft_calloc(1, sizeof(*stacks));
	if (!stacks)
	{
		if (argv == 2)
			ft_freestrarray(array);
		ft_error ();
	}
	i = -1;
	while (array[++i])
	{
		new = ft_stacknew(ft_atoi(array[i]));
		if (!new)
		{
			if (argv == 2)
				ft_freestrarray(array);
			ft_errorandfree(stacks);
		}
		ft_stackadd_back(&stacks->a, new);
	}
	return (stacks);
}
