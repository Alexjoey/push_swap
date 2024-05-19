#include "../includes/push_swap.h"

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
