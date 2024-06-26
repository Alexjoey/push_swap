/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:05:32 by amylle            #+#    #+#             */
/*   Updated: 2024/02/22 00:55:33 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*stack)
		return ;
	tmp = *stack;
	if (tmp->next == NULL)
		return ;
	tail = ft_stacklast(*stack);
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->a);
	reverse_rotate(&stacks->b);
	ft_putstr_fd("rrr\n", 1);
}
