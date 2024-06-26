/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:18:26 by labdello          #+#    #+#             */
/*   Updated: 2024/06/26 15:08:25 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h" 
# include <limits.h>

typedef struct s_stack
{
	size_t			index;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int	stk_size(t_stack *stack);
t_stack	*stk_new(int value);
t_stack	*stk_last(t_stack *stack);
void	stk_clear(t_stack **stack);
void	stk_indexing(t_stack *stack);
void	stk_add(t_stack **stack, t_stack *new);

void	swap(t_stack **stack);
void	swap_s(t_stack **a_stack, t_stack **b_stack);
void	push(t_stack **sender, t_stack **receiver);

#endif
