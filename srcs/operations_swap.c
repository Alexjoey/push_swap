/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:33:52 by amylle            #+#    #+#             */
/*   Updated: 2024/02/27 17:02:52 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *root)
{
	t_stack	*sec;
	int		temp;

	if (!root)
		return ;
	sec = root->next;
	temp = root->content;
	root->content = sec->content;
	sec->content = temp;
}

void	sa(t_stacks *stacks)
{
	swap(stacks->a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	swap(stacks->b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	swap(stacks->a);
	swap(stacks->b);
	ft_putstr_fd("ss\n", 1);
}
