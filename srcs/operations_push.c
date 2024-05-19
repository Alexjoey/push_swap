/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:51:59 by amylle            #+#    #+#             */
/*   Updated: 2024/02/27 16:56:16 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **receiver, t_stack **giver)
{
	t_stack	*temp;

	temp = *giver;
	*giver = (*giver)->next;
	temp->next = *receiver;
	*receiver = temp;
}

void	pa(t_stacks *stacks)
{
	push(&stacks->a, &stacks->b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	push(&stacks->b, &stacks->a);
	ft_putstr_fd("pb\n", 1);
}
