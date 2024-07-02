/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:22:30 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 22:14:27 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_indexes(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack != NULL)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	update_target(t_stack *a_stk, t_stack *b_stk)
{
	t_stack	*target;
	t_stack	*current;

	while (b_stk != NULL)
	{
		target = b_stk;
		current = a_stk;
		while (current != NULL)
		{
			if (current->value > b_stk->value && current->value < target->value)
				target = current;
			current = current->next;
		}
		if (b_stk == target)
			b_stk->target = stk_smallest(a_stk);
		else
			b_stk->target = target;
		b_stk = b_stk->next;
	}
}

void	update_prices(t_stack *a_stack, t_stack *b_stack)
{
	size_t	a_len;
	size_t	b_len;

	a_len = stk_size(a_stack);
	b_len = stk_size(b_stack);
	while (b_stack != NULL)
	{
		b_stack->price = b_stack->index;
		if (!is_above_median(b_stack))
			b_stack->price = b_len - (b_stack->index);
		if (is_above_median(b_stack->target))
			b_stack->price += b_stack->target->index;
		else
			b_stack->price += a_len - (b_stack->target->index);
		b_stack = b_stack->next;
	}
}

void	update_nodes(t_stack *a_stack, t_stack *b_stack)
{
	update_indexes(a_stack);
	update_indexes(b_stack);
	update_target(a_stack, b_stack);
	update_prices(a_stack, b_stack);
}
