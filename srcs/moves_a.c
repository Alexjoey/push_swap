#include "../includes/push_swap.h"
#include <limits.h>

int	find_closest_bigger_val(t_stacks *stacks, int i)
{
	int		min_diff;
	long	temp;
	t_stack	*ptr;
	int		ret_val;

	ret_val = 0;
	ptr = stacks->a;
	min_diff = INT_MAX;
	while (ptr)
	{
		temp = ptr->content - i;
		if (temp > 0 && temp < min_diff)
		{
			min_diff = temp;
			ret_val = ptr->content;
		}
		ptr = ptr->next;
	}
	if (ret_val == 0)
		return (ft_mininstack(stacks->a));
	return (ret_val);
}

void	put_a_in_order(t_stacks *stacks)
{
	int	i;
	int	size;
	int	min;

	min = ft_mininstack(stacks->a);
	i = find_index_by_value(stacks->a, min);
	if (i == 0)
		return ;
	size = ft_stacksize(stacks->a);
	if (i >= (size + 1) / 2)
		stacks->moves->rra = (size - i);
	else
		stacks->moves->ra = i;
	while (stacks->moves->rra-- > 0)
		rra(stacks);
	while (stacks->moves->ra-- > 0)
		ra(stacks);
}

//after all has been pushed to b besides 3 elements
//find the target of current b, because of how its pushed you only need rra
//then put min value as n1 of the stack
void	push_to_a(t_stacks *stacks)
{
	while (stacks->b)
	{
		while (!(stacks->a->content == find_closest_bigger_val(stacks, stacks->b->content)))
			rra(stacks);
		pa(stacks);
	}
	put_a_in_order(stacks);
}
