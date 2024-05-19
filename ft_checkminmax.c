#include "includes/push_swap.h"


void	ft_checkminmax(t_stacks *stacks, char c)
{
	if (c == 'a')
	{
		stacks->val->max_a = ft_maxinstack(stacks->a);
		stacks->val->min_a = ft_mininstack(stacks->a);
	}
	else if (c == 'b')
	{
		stacks->val->max_b = ft_maxinstack(stacks->b);
		stacks->val->min_b = ft_mininstack(stacks->b);
	}
}

int	ft_maxinstack(t_stack *stack)
{
	int		i;
	t_stack *temp;

	temp = stack;
	i = temp->content;
	while (temp->next)
	{
		temp = temp->next;
		if (i < temp->content)
			i = temp->content;
	}
	return (i);
}

int	ft_mininstack(t_stack *stack)
{
	int		i;
	t_stack *temp;

	temp = stack;
	i = temp->content;
	while (temp->next)
	{
		temp = temp->next;
		if (i > temp->content)
			i = temp->content;
	}
	return (i);
}
