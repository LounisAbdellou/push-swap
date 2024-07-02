/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:00:53 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 22:46:10 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_above_median(t_stack *stack)
{
	size_t	centerline;
	t_stack	*first_node;

	first_node = stk_first(stack);
	centerline = stk_size(first_node) / 2;
	if (stack->index <= centerline)
		return (1);
	return (0);
}

t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_node = stack;
	while (stack != NULL)
	{
		if (stack->price < cheapest_node->price)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}
