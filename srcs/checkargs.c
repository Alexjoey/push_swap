/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:06:14 by amylle            #+#    #+#             */
/*   Updated: 2024/02/28 14:38:03 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

static int	checkint(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->content < INT_MIN || stack_a->content > INT_MAX)
			return(1);
		stack_a = stack_a->next;
	}
	return (0);
}

static int	checkduplicates(t_stack *stack_a)
{
	t_stack	*check;

	while (stack_a && stack_a->next)
	{
		check = stack_a->next;
		while (check)
		{
			if(stack_a->content == check->content)
				return (1);
			check = check->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_checkargs(t_stack *stack_a)
{
	if (checkduplicates(stack_a))
		return (0);
	else if (checkint(stack_a))
		return (0);
	else
		return (1);
}
