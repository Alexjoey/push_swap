/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:10:54 by amylle            #+#    #+#             */
/*   Updated: 2024/02/28 13:13:27 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_freestrarray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (i-- > 0)
		free (array[i]);
	free (array);
}

void	ft_errorandfree(t_stacks *stacks)
{
	ft_clearall(stacks);
	ft_error ();
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	while (stack && *stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
}

void	ft_clearall(t_stacks *stacks)
{
	ft_stackclear(&stacks->a);
	ft_stackclear(&stacks->b);
	free (stacks->moves);
	free (stacks->cost);
	free (stacks);
}
