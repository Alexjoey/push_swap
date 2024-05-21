#include "../includes/push_swap.h"

void	cost_double_moves(t_stacks *stacks)
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

void	cost_update(t_stacks *stacks, int i)
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
		cost_double_moves(stacks);
		cost_update(stacks, i);
		curr = curr->next;
		i++;
	}
}
