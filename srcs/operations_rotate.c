/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 21:55:40 by amylle            #+#    #+#             */
/*   Updated: 2024/02/22 00:59:09 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*stack)
		return ;
	tmp = *stack;
	if (tmp->next == NULL)
		return ;
	tail = ft_stacklast(tmp);
	*stack = tmp->next;
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_stacks *stacks)
{
	rotate(&stacks->a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stacks *stacks)
{
	rotate(&stacks->a);
	rotate(&stacks->b);
	ft_putstr_fd("rr\n", 1);
}
