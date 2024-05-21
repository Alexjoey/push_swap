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

#include "../includes/push_swap.h"
#include <limits.h>

// calculates moves for current node to get to top of the stack
// look through the whole stack
// target will always be next smallest number
// or if youre smallest, then your target is max of b
int	find_closest_smaller_val(t_stacks *stacks, int i)
{
	int		min_diff;
	long	temp;
	t_stack	*ptr;
	int		ret_val;

	ret_val = 0;
	ptr = stacks->b;
	min_diff = INT_MIN;
	while (ptr)
	{
		temp = ptr->content - i;
		if (temp < 0 && temp > min_diff)
		{
			min_diff = temp;
			ret_val = ptr->content;
		}
		ptr = ptr->next;
	}
	if (ret_val == 0)
		return (ft_maxinstack(stacks->b));
	return (ret_val);
}

void	ft_threesort(t_stacks *stacks)
{
	int		highest;
	t_stack	*index;

	index = stacks->a;
	highest = index->content;
	while (index)
	{
		if (index->content > highest)
			highest = index->content;
		index = index->next;
	}
	if (stacks->a->content == highest)
		ra(stacks);
	else if (stacks->a->next->content == highest)
		rra(stacks);
	if (stacks->a->content > stacks->a->next->content)
		sa(stacks);
}

void	do_moves(t_stacks *stacks)
{
	while (stacks->cost->ra-- > 0)
		ra(stacks);
	while (stacks->cost->rb-- > 0)
		rb(stacks);
	while (stacks->cost->rr-- > 0)
		rr(stacks);
	while (stacks->cost->rra-- > 0)
		rra(stacks);
	while (stacks->cost->rrb-- > 0)
		rrb(stacks);
	while (stacks->cost->rrr-- > 0)
		rrr(stacks);
	while (stacks->cost->pb-- > 0)
		pb(stacks);
}

void	ft_movecheapest(t_stacks *stacks)
{
	t_moves	*moves;
	t_moves	*cost;

	stacks->moves = ft_calloc(1, sizeof(*moves));
	stacks->cost = ft_calloc(1, sizeof(*cost));
	if (!stacks->moves || !stacks->cost)
		ft_errorandfree(stacks);
	while (ft_stacksize(stacks->a) != 3)
	{
		ft_calcmoves(stacks);
		do_moves(stacks);
	}
}

void	ft_sort(t_stacks *stacks)
{
	if (ft_issorted(stacks->a) == true)
		return ;
	else if (ft_stacksize(stacks->a) <= 3)
		ft_threesort(stacks);
	else
	{
		if (ft_stacksize(stacks->a) > 4)
			pb(stacks);
		pb(stacks);
		ft_movecheapest(stacks);
		ft_threesort(stacks);
		push_to_a(stacks);
	}
}
