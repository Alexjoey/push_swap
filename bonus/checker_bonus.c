/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:57 by amylle            #+#    #+#             */
/*   Updated: 2024/05/22 16:33:58 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_freeandexit_bonus(t_stacks *stacks, char *cmd)
{
	free (cmd);
	ft_clearall(stacks);
	ft_error();
}

static void	do_cmd(t_stacks *stacks, char *cmd)
{
	if (!ft_strncmp(cmd, "ra\n", 3))
		return (rotate(&stacks->a));
	if (!ft_strncmp(cmd, "rb\n", 3))
		return (rotate(&stacks->b));
	if (!ft_strncmp(cmd, "rr\n", 3))
		return (rotate(&stacks->a), rotate(&stacks->b));
	if (!ft_strncmp(cmd, "rra\n", 3))
		return (reverse_rotate(&stacks->a));
	if (!ft_strncmp(cmd, "rrb\n", 3))
		return (reverse_rotate(&stacks->b));
	if (!ft_strncmp(cmd, "rrr\n", 3))
		return (reverse_rotate(&stacks->a), reverse_rotate(&stacks->b));
	if (!ft_strncmp(cmd, "sa\n", 3))
		return (swap(stacks->a));
	if (!ft_strncmp(cmd, "sb\n", 3))
		return (swap(stacks->b));
	if (!ft_strncmp(cmd, "ss\n", 3))
		return (swap(stacks->a), swap(stacks->b));
	if (!ft_strncmp(cmd, "pa\n", 3))
		return (push(&stacks->a, &stacks->b));
	if (!ft_strncmp(cmd, "pb\n", 3))
		return (push(&stacks->b, &stacks->a));
	ft_freeandexit_bonus(stacks, cmd);
}

static void	ft_exec_commands(t_stacks *stacks)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			return ;
		do_cmd(stacks, cmd);
		free (cmd);
		cmd = NULL;
	}
}

int	main(int argv, char **argc)
{
	t_stacks	*stacks;
	char		**array;

	if (argv == 2)
	{
		array = ft_split(argc[1], ' ');
		ft_input_error(argv, array);
		stacks = ft_initstacks(argv, array);
		ft_freestrarray(array);
	}
	else
	{
		ft_input_error(argv, ++argc);
		stacks = ft_initstacks(argv, argc);
	}
	if (!stacks->a || ft_checkduplicates(stacks->a))
		ft_errorandfree(stacks);
	ft_exec_commands(stacks);
	if (ft_issorted(stacks->a) == true && ft_stacksize(stacks->b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_clearall(stacks);
}
