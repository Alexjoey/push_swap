/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:04:51 by amylle            #+#    #+#             */
/*   Updated: 2024/02/22 01:03:48 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacknew(int n);
void	ft_stackadd_back(t_stack **lst, t_stack *new);

void	swap(t_stack *root);

void	push(t_stack **giver, t_stack **receiver);

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
