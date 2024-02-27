/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:14:13 by amylle            #+#    #+#             */
/*   Updated: 2024/02/22 01:02:18 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	printstack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
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

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_stacklast(*lst);
	last->next = new;
}

int	main(int argv, char **argc)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	if (argv > 1)
	{
		stack_a = ft_stacknew(ft_atoi(argc[i]));
		while (argc[++i])
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argc[i])));
		printstack(stack_a);
	}
	rra(&stack_a);
	printstack(stack_a);
}
