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

# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void	ft_error(void);
void	ft_freearrayerror(char **array);
void	ft_freestrarray(char **array);

long	ft_atol(const char *nptr);
int		ft_checkduplicates(t_stack *stack_a);
int		ft_checkint(char **argc);

t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int n);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **stack);
void	printstacks(t_stack *stack_a, t_stack *stack_b);
t_stack	*ft_makestack(int argv, char **argc);

void	swap(t_stack *root);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	push(t_stack **giver, t_stack **receiver);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		ft_issorted(t_stack *stack_a);
void	ft_threesort(t_stack **stack_a);

#endif
