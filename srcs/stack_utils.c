/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:14:13 by amylle            #+#    #+#             */
/*   Updated: 2024/02/27 16:42:51 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	printstacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("a       b\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d   |", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("    |");
		if (stack_b)
		{
			printf("   %d", stack_b->content);
			stack_b = stack_b->next;
		}
		printf("\n");
	}
}

t_stack	*ft_stacknew(int n)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = n;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
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
