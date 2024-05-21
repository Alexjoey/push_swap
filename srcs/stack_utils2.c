#include "../includes/push_swap.h"

int	find_index_by_value(t_stack *stack, int i)
{
	int		index;
	t_stack	*ptr;

	index = 0;
	ptr = stack;
	while (ptr)
	{
		if (ptr->content == i)
			return (index);
		index++;
		ptr = ptr->next;
	}
	return (index);
}

bool	ft_issorted(t_stack *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}

int	ft_maxinstack(t_stack *stack)
{
	int		i;
	t_stack	*temp;

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
	t_stack	*temp;

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
