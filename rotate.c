/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:08 by labdello          #+#    #+#             */
/*   Updated: 2024/06/26 17:33:23 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (stk_size(*(stack)) < 2)
		return ;
	tmp = *stack;
	last = stk_last(*(stack));
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	tmp->prev = last;
	last->next = tmp;
	stk_indexing(*(stack));
}

void	rotate_r(t_stack **a_stack, t_stack **b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (stk_size(*(stack)) < 2)
		return ;
	last = stk_last(*(stack));
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	last->next = *stack;
	*stack = last;
	stk_indexing(*(stack));
}

void	reverse_rotate_r(t_stack **a_stack, t_stack **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
}
