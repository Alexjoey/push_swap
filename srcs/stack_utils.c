/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:14:13 by amylle            #+#    #+#             */
/*   Updated: 2024/03/01 16:55:49 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printstacks(t_stacks *stacks)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = stacks->a;
	temp_b = stacks->b;
	ft_printf("a       b\n");
	while (temp_a || temp_b)
	{
		if (temp_a)
		{
			ft_printf("%d   |", temp_a->content);
			temp_a = temp_a->next;
		}
		else
			ft_printf("    |");
		if (temp_b)
		{
			ft_printf("   %d", temp_b->content);
			temp_b = temp_b->next;
		}
		ft_printf("\n");
	}
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
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
