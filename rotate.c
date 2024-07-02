/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:08 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 15:24:53 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char *action)
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
	if (action != NULL)
		ft_putstr_fd(action, 1);
}

void	rotate_r(t_stack **a_stack, t_stack **b_stack)
{
	rotate(a_stack, NULL);
	rotate(b_stack, NULL);
	ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate(t_stack **stack, char *action)
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
	if (action != NULL)
		ft_putstr_fd(action, 1);
}

void	reverse_rotate_r(t_stack **a_stack, t_stack **b_stack)
{
	reverse_rotate(a_stack, NULL);
	reverse_rotate(b_stack, NULL);
	ft_putstr_fd("rrr\n", 1);
}
