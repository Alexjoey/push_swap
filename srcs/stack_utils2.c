#include "../includes/push_swap.h"

void	ft_errorandfree(t_stacks *stacks)
{
	ft_clearall(stacks);
	ft_error ();
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

void	ft_clearall(t_stacks *stacks)
{
	ft_stackclear(&stacks->a);
	ft_stackclear(&stacks->b);
	free (stacks->moves);
	free (stacks->cost);
	free (stacks);
}
