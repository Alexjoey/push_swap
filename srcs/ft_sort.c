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

// calculates moves for current node to get to top of the stack
void	cost_rotate_a(t_stacks *stacks, t_stack *curr, int i)
{
	int	size;

	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a->content == curr->content)
		return ;
	size = ft_stacksize(stacks->a);
	if (i >= (size + 1) / 2)
		stacks->moves->rra = (size - i);
	else
		stacks->moves->ra = i;
}

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


//calculate cost to place value i into the stack
void	cost_rotate_b(t_stacks *stacks, int i)
{
	int	nbr;
	int	ind;
	int	size;

	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	nbr = find_closest_smaller_val(stacks, i);
	ind = find_index_by_value(stacks->b, nbr);
	size = ft_stacksize(stacks->b);
	if (ind >= (size + 1) / 2)
		stacks->moves->rrb = (size - ind);
	else
		stacks->moves->rb = ind;
}

void	calc_double_moves(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra != 0 && stacks->moves->rb != 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra != 0 && stacks->moves->rrb != 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}

void	calc_update_cost(t_stacks *stacks, int i)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra \
	+ stacks->moves->rb + stacks->moves->rr + stacks->moves->rra \
	+ stacks->moves->rrb + stacks->moves->rrr;
	if (i == 0 || stacks->cost->cost > stacks->moves->cost)
	{
		stacks->cost->cost = stacks->moves->cost;
		stacks->cost->pb = stacks->moves->pb;
		stacks->cost->ra = stacks->moves->ra;
		stacks->cost->rb = stacks->moves->rb;
		stacks->cost->rr = stacks->moves->rr;
		stacks->cost->rra = stacks->moves->rra;
		stacks->cost->rrb = stacks->moves->rrb;
		stacks->cost->rrr = stacks->moves->rrr;
	}
}

void	ft_calcmoves(t_stacks *stacks)
{
	int		i;
	t_stack	*curr;

	i = 0;
	curr = stacks->a;
	while (curr)
	{
		cost_rotate_a(stacks, curr, i);
		cost_rotate_b(stacks, curr->content);
		calc_double_moves(stacks);
		calc_update_cost(stacks, i);
		curr = curr->next;
		i++;
	}
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
