/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:01 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 15:19:26 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *action)
{
	t_stack	*tmp;

	if (stk_size(*(stack)) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	tmp->prev = *stack;
	(*stack)->prev = NULL;
	(*stack)->next = tmp;
	if (action != NULL)
		ft_putstr_fd(action, 1);
}

void	swap_s(t_stack **a_stack, t_stack **b_stack)
{
	swap(a_stack, NULL);
	swap(b_stack, NULL);
	ft_putstr_fd("ss\n", 1);
}
