/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labdello <labdello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:53:17 by labdello          #+#    #+#             */
/*   Updated: 2024/07/02 20:31:32 by labdello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stk_size(t_stack *stack)
{
	size_t	count;

	count = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*stk_smallest(t_stack *stack)
{
	t_stack	*smallest_node;

	if (!stack)
		return (NULL);
	smallest_node = stack;
	while (stack != NULL)
	{
		if (stack->value < smallest_node->value)
		{
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

t_stack	*stk_biggest(t_stack *stack)
{
	t_stack	*biggest_node;

	if (!stack)
		return (NULL);
	biggest_node = stack;
	while (stack != NULL)
	{
		if (stack->value > biggest_node->value)
		{
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

int	is_stk_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stk_display(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_putnbr_fd(stack->index, 1);
		ft_putstr_fd(" => ", 1);
		ft_putnbr_fd(stack->value, 1);
		ft_putstr_fd("\n", 1);
		stack = stack->next;
	}
}
