/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:04:51 by amylle            #+#    #+#             */
/*   Updated: 2024/03/19 15:45:25 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_moves
{
	int	cost;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_moves;

typedef struct s_cost
{
	int	cost;
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}		t_cost;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	t_cost	*cost;
	t_moves	*moves;
}			t_stacks;

void		ft_error(void);

void		ft_input_error(int argc, char **argv);
int			ft_checkduplicates(t_stack *stack_a);
bool		ft_isinputint(char **argc);
void		ft_errorandfree(t_stacks *stacks);
void		ft_freestrarray(char **argc);

t_stack		*ft_stacklast(t_stack *lst);
t_stack		*ft_stacknew(int n);
void		ft_stackadd_back(t_stack **lst, t_stack *newstack);
void		ft_stackclear(t_stack **stack);
void		printstacks(t_stacks *stacks);
t_stacks	*ft_initstacks(int argv, char **argc);
int			ft_stacksize(t_stack *stack);

void		swap(t_stack *root);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);

void		push(t_stack **giver, t_stack **receiver);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		rotate(t_stack **stack);
void		ra(t_stacks *stacks);
void		rb(t_stacks*stacks);
void		rr(t_stacks *stacks);

void		reverse_rotate(t_stack **stack);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

bool		ft_issorted(t_stack *stack_a);
void		ft_threesort(t_stacks *stack_a);
void		ft_sort(t_stacks *stacks);
void		ft_clearall(t_stacks *stacks);

void		ft_movecheapest(t_stacks *stacks);
void		calc_double_moves(t_stacks *stacks);
void		ft_calcmoves(t_stacks *stacks);

void		ft_checkminmax(t_stacks *stacks, char c);
int			ft_maxinstack(t_stack *stack);
int			ft_mininstack(t_stack *stack);
int			find_index_by_value(t_stack *stack, int i);
void		push_to_a(t_stacks *stacks);
int			find_closest_smaller_val(t_stacks *stacks, int i);

#endif
