/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:18:28 by amylle            #+#    #+#             */
/*   Updated: 2024/03/19 15:45:08 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_threesort(t_stack **stack_a)
{
	int		highest;
	t_stack	*index;

	if (ft_issorted(*stack_a))
		return ;
	index = *stack_a;
	highest = index->content;
	while (index)
	{
		if (index->content > highest)
			highest = index->content;
		index = index->next;
	}
	if ((*stack_a)->content == highest)
		ra(stack_a);
	else if ((*stack_a)->next->content == highest)
		rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(*stack_a);
}
